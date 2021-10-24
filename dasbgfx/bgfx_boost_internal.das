options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost_internal shared

require daslib/ast_boost
require daslib/templates
require daslib/templates_boost
require daslib/safe_addr

require bgfx

[structure_macro(name="bgfx_vertex_buffer")]
class BgfxVertexBuffer : AstStructureAnnotation
    def override apply ( var st:StructurePtr; var group:ModuleGroup; args:AnnotationArgumentList; var errors : das_string ) : bool
        var fn <- new [[Function() at = st.at, atDecl = st.at, name := "bgfx_create_vertex_layout"]]
        fn.flags |= FunctionFlags generated
        fn.result <- new [[TypeDecl() baseType=Type autoinfer, at=st.at]]
        fn.arguments |> emplace_new() <| new [[Variable() at=st.at,
            name := "self",
            _type <- new [[TypeDecl() at=st.at,
                baseType=Type tStructure,
                structType=get_ptr(st)
            ]]
        ]]
        fn.arguments |> emplace_new() <| new [[Variable() at=st.at,
            name := "render_type",
            _type <- clone_type() <| typeinfo(ast_typedecl type<bgfx_renderer_type>)
        ]]
        var qblk <- quote() <|
            var pcv_decl : bgfx_vertex_layout_s
            bgfx_vertex_layout_begin(safe_addr(pcv_decl), render_type)
            declarations_go_here
            bgfx_vertex_layout_end(safe_addr(pcv_decl))
            return pcv_decl
        var blk <- new [[ExprBlock() at=st.at]]
        var saddr <- new [[ExprCall() at=st.at, name:="safe_addr"]]
        saddr.arguments |> emplace_new <| new [[ExprVar() at=st.at, name:="pcv_decl"]]
        let bgfx_attr_enum_t = typeinfo(ast_typedecl type<bgfx_attrib>).enumType
        let bgfx_attr_type_enum_t = typeinfo(ast_typedecl type<bgfx_attrib_type>).enumType
        for fld in st.fields
            let semantics = find_arg("semantics", fld.annotation)
            if !(semantics is tString )
                errors := "field {fld.name} is missing 'semantics'"
                return false
            let sizei = find_arg("size", fld.annotation)
            if !(sizei is tInt)
                errors := "field {fld.name} is missing 'size'"
                return false
            let typet = find_arg("type", fld.annotation)
            if !(typet is tString)
                errors := "field {fld.name} is missing 'type'"
                return false
            let normalized = (find_arg("normalized", fld.annotation) ?as tBool) ?? false
            let as_int = (find_arg("as_int", fld.annotation) ?as tBool) ?? false
            // bgfx_vertex_layout_add(safe_addr(pcv_decl), bgfx_attrib BGFX_ATTRIB_POSITION, 3u, bgfx_attrib_type BGFX_ATTRIB_TYPE_FLOAT, false, false)
            var cll_vap <- new [[ExprCall() at=fld.at, name:="bgfx_vertex_layout_add"]]
            cll_vap.arguments |> emplace_new() <| clone_expression(saddr)
            cll_vap.arguments |> emplace_new() <| new [[ExprConstEnumeration() at=st.at, enumType:=bgfx_attr_enum_t, value:="BGFX_ATTRIB_{semantics as tString}"]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstUInt() at=st.at, value=uint(sizei as tInt)]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstEnumeration() at=st.at, enumType:=bgfx_attr_type_enum_t, value:="BGFX_ATTRIB_TYPE_{typet as tString}"]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstBool() at=st.at, value=normalized]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstBool() at=st.at, value=as_int]]
            blk.list |> emplace(cll_vap)
        saddr := null
        apply_template(qblk) <| $ ( rules )
            rules |> replaceVariable("declarations_go_here") <| blk
        var qres <- move_unquote_block(qblk)
        qres.blockFlags &= ~ExprBlockFlags isClosure
        fn.body <- qres
        append_annotation(fn,"templates","template",[{auto[]
            [[auto "self", [[RttiValue tBool=true]] ]]
        }])
        if !(compiling_module() |> add_function(fn))
            panic("can't setup")
        return true


