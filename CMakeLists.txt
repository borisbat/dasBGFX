
IF (NOT DAS_BGFX_INCLUDED)
    SET(DAS_BGFX_INCLUDED TRUE)
    MESSAGE(STATUS "dasBgfx module included.")

	SET(DAS_BGFX_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX)
	SET(DAS_BGFX_KHRONOS_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty/khronos)
	SET(DAS_BGFX_DX12_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty/dxsdk/include)
	SET(DAS_BGFX_COMPAT_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/include/compat/msvc)
	SET(DAS_BGFX_ASTC_CODEC_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/3rdparty/astc-codec/include)

	SET(DAS_BX_INCLUDE_DIR   ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/include)
	SET(DAS_BGFX_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/include)
	SET(DAS_BIMG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/include)

	SET(DAS_BX_3P_INCLUDE_DIR   ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bx/3rdparty)
	SET(DAS_BGFX_3P_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bgfx/3rdparty)
	SET(DAS_BIMG_3P_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/modules/dasBGFX/bgfx/bimg/3rdparty)


    LIST(APPEND CMAKE_MODULE_PATH ${DAS_BGFX_DIR})

	# libBGFX
	SET(LIB_BGFX_SRC
		${DAS_BGFX_DIR}/bgfx/bgfx/src/amalgamated.cpp
		${DAS_BGFX_DIR}/bgfx/bx/src/amalgamated.cpp
		${DAS_BGFX_DIR}/bgfx/bimg/src/image.cpp
		${DAS_BGFX_DIR}/bgfx/bimg/src/image_gnf.cpp
	)

	# libDasModuleBGFX
	SET(DAS_BGFX_MODULE_SRC
		${DAS_BGFX_DIR}/src/dasBGFX.h
		${DAS_BGFX_DIR}/src/dasBGFX.cpp
		${DAS_BGFX_DIR}/src/need_bgfx.h
		${DAS_BGFX_DIR}/src/module_bgfx.ann.cpp_inc
		${DAS_BGFX_DIR}/src/module_bgfx.ann.inc
		${DAS_BGFX_DIR}/src/module_bgfx.enum.cpp_inc
		${DAS_BGFX_DIR}/src/module_bgfx.enum.inc
		${DAS_BGFX_DIR}/src/module_bgfx.h
		${DAS_BGFX_DIR}/src/module_bgfx.inc
		${DAS_BGFX_DIR}/src/module_bgfx.method.inc
	)

	ADD_MODULE_LIB(libDasModuleBGFX)
	ADD_MODULE_CPP(BGFX)
	# ADD_MODULE_NATIVE(stbimage_boost)
	ADD_LIBRARY(libDasModuleBGFX ${DAS_BGFX_MODULE_SRC} ${LIB_BGFX_SRC})
	TARGET_LINK_LIBRARIES(libDasModuleBGFX ${BGFX_LIBRARIES})
	ADD_DEPENDENCIES(libDasModuleBGFX libDaScript)
	target_compile_definitions(libDasModuleBGFX PUBLIC -DBIMG_DECODE_ASTC=0)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleBGFX PUBLIC

	${DAS_BX_INCLUDE_DIR} 	${DAS_BX_3P_INCLUDE_DIR}
		${DAS_BGFX_INCLUDE_DIR} ${DAS_BGFX_3P_INCLUDE_DIR}
		${DAS_BIMG_INCLUDE_DIR} ${DAS_BIMG_3P_INCLUDE_DIR}
		${DAS_BGFX_COMPAT_DIR}
		${DAS_BGFX_KHRONOS_DIR}
		${DAS_BGFX_DX12_DIR}
		${DAS_BGFX_ASTC_CODEC_DIR}
	)
	SETUP_CPP11(libDasModuleBGFX)

	ADD_MODULE_DAS(dasbgfx dasbgfx bgfx_boost)

	IF(WIN32)
		# GENERATE BGFIX
		DAS_CPP_BIND_AST(
			BGFX_GENERATE
			generate_bgfx.das
			${DAS_BGFX_DIR}/src/bgfx_headers.h
			${DAS_BGFX_DIR}/src/module_bgfx
			${DAS_BGFX_DIR}/src
			"${DAS_BGFX_INCLUDE_DIR}"
			"${DAS_BGFX_INCLUDE_DIR}/bgfx/defines.h"
		)
	ENDIF()

ENDIF()
