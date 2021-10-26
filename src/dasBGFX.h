#pragma once

#include "bgfx_headers.h"

namespace das {
void Das_bgfx_dbg_text_printf(uint16_t _x, uint16_t _y, uint8_t _attr, const char* text );
float4x4 Das_bgfx_projection ( float angleD, float w, float h, float zn, float zf, bool HD, bool lh );
float4x4 Das_bgfx_ortho ( float l, float r, float b, float t, float zn, float zf, float ofs, bool HD, bool lh );

}

