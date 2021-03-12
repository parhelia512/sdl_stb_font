static const uint8_t vs_textured_passthrough_bin_glsl[] = {
  0x56, 0x53, 0x48, 0x09, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x1e, 0x3e, 0x3c, 0x01, 0x00, 0x0f, 0x75,  // VSH.....o.><...u
  0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01,  // _modelViewProj..
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x01, 0x00, 0x00, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62,  // ..........attrib
  0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x33, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74,  // ute vec3 a_posit
  0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76,  // ion;.attribute v
  0x65, 0x63, 0x32, 0x20, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b,  // ec2 a_texcoord0;
  0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f,  // .varying vec2 v_
  0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f,  // texcoord0;.unifo
  0x72, 0x6d, 0x20, 0x6d, 0x61, 0x74, 0x34, 0x20, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56,  // rm mat4 u_modelV
  0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61,  // iewProj;.void ma
  0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74,  // in ().{.  vec4 t
  0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61,  // mpvar_1;.  tmpva
  0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x74,  // r_1.w = 1.0;.  t
  0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x61, 0x5f,  // mpvar_1.xyz = a_
  0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50,  // position;.  gl_P
  0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, 0x6d, 0x6f, 0x64,  // osition = (u_mod
  0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70,  // elViewProj * tmp
  0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63,  // var_1);.  v_texc
  0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f,  // oord0 = a_texcoo
  0x72, 0x64, 0x30, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00 };                                          // _texcoord0;.}...
unsigned int vs_textured_passthrough_bin_glsl_size = 313;

BX_UNUSED(vs_textured_passthrough_bin_glsl)
BX_UNUSED(vs_textured_passthrough_bin_glsl_size)
static const uint8_t vs_textured_passthrough_bin_dx9[] = {
  0x56, 0x53, 0x48, 0x09, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x1e, 0x3e, 0x3c, 0x01, 0x00, 0x0f, 0x75,  // VSH.....o.><...u
  0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x00,  // _modelViewProj..
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0x0b, 0x6a,  // ..........DXBC.j
  0x72, 0xae, 0x8a, 0xf0, 0xc5, 0xba, 0x55, 0x23, 0xc7, 0x67, 0xc5, 0xc7, 0xe9, 0x83, 0x01, 0x00,  // r.....U#.g......
  0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x80, 0x00,  // ..........,.....
  0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00,  // ......ISGNL.....
  0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......8.........
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x41, 0x00,  // ..............A.
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,  // ................
  0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x54,  // ......POSITION.T
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x50, 0x00,  // EXCOORD...OSGNP.
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..........8.....
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,  // ................
  0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..D.............
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53,  // ..........SV_POS
  0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab,  // ITION.TEXCOORD..
  0xab, 0xab, 0x53, 0x48, 0x44, 0x52, 0xfc, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x3f, 0x00,  // ..SHDR....@...?.
  0x00, 0x00, 0x59, 0x00, 0x00, 0x04, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,  // ..Y...F. .......
  0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, 0x72, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x00,  // .._...r......._.
  0x00, 0x03, 0x32, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x04, 0xf2, 0x20,  // ..2.......g.... 
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0x32, 0x20,  // ..........e...2 
  0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x38, 0x00,  // ......h.......8.
  0x00, 0x08, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x15, 0x10, 0x00, 0x00, 0x00,  // ..........V.....
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00,  // ..F. .........2.
  0x00, 0x0a, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00,  // ..........F. ...
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e,  // ..............F.
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0a, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00,  // ......2.........
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xa6, 0x1a,  // ..F. ...........
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......F.........
  0x00, 0x08, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00,  // ... ......F.....
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00,  // ..F. .........6.
  0x00, 0x05, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x01, 0x00,  // ..2 ......F.....
  0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x02, 0x01, 0x00, 0x10, 0x00, 0x40, 0x00 };            // ....>.........@.
unsigned int vs_textured_passthrough_bin_dx9_size = 526;

BX_UNUSED(vs_textured_passthrough_bin_dx9)
BX_UNUSED(vs_textured_passthrough_bin_dx9_size)
static const uint8_t vs_textured_passthrough_bin_dx11[] = {
  0x56, 0x53, 0x48, 0x09, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x1e, 0x3e, 0x3c, 0x01, 0x00, 0x0f, 0x75,  // VSH.....o.><...u
  0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x00,  // _modelViewProj..
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0x0b, 0x6a,  // ..........DXBC.j
  0x72, 0xae, 0x8a, 0xf0, 0xc5, 0xba, 0x55, 0x23, 0xc7, 0x67, 0xc5, 0xc7, 0xe9, 0x83, 0x01, 0x00,  // r.....U#.g......
  0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x80, 0x00,  // ..........,.....
  0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00,  // ......ISGNL.....
  0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......8.........
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x41, 0x00,  // ..............A.
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,  // ................
  0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x54,  // ......POSITION.T
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x50, 0x00,  // EXCOORD...OSGNP.
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..........8.....
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,  // ................
  0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..D.............
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53,  // ..........SV_POS
  0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab,  // ITION.TEXCOORD..
  0xab, 0xab, 0x53, 0x48, 0x44, 0x52, 0xfc, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x3f, 0x00,  // ..SHDR....@...?.
  0x00, 0x00, 0x59, 0x00, 0x00, 0x04, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,  // ..Y...F. .......
  0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, 0x72, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x00,  // .._...r......._.
  0x00, 0x03, 0x32, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x04, 0xf2, 0x20,  // ..2.......g.... 
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0x32, 0x20,  // ..........e...2 
  0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x38, 0x00,  // ......h.......8.
  0x00, 0x08, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x15, 0x10, 0x00, 0x00, 0x00,  // ..........V.....
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00,  // ..F. .........2.
  0x00, 0x0a, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00,  // ..........F. ...
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e,  // ..............F.
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0a, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00,  // ......2.........
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xa6, 0x1a,  // ..F. ...........
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......F.........
  0x00, 0x08, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00,  // ... ......F.....
  0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00,  // ..F. .........6.
  0x00, 0x05, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x01, 0x00,  // ..2 ......F.....
  0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x02, 0x01, 0x00, 0x10, 0x00, 0x40, 0x00 };            // ....>.........@.
unsigned int vs_textured_passthrough_bin_dx11_size = 526;

BX_UNUSED(vs_textured_passthrough_bin_dx11)
BX_UNUSED(vs_textured_passthrough_bin_dx11_size)
static const uint8_t vs_textured_passthrough_bin_metal[] = {
  0x56, 0x53, 0x48, 0x09, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x1e, 0x3e, 0x3c, 0x01, 0x00, 0x0f, 0x75,  // VSH.....o.><...u
  0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01,  // _modelViewProj..
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x85, 0x02, 0x00, 0x00, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75,  // ..........#inclu
  0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, 0x74, 0x64, 0x6c, 0x69, 0x62,  // de <metal_stdlib
  0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64,  // >.#include <simd
  0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20,  // /simd.h>..using 
  0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b,  // namespace metal;
  0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x5f, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c,  // ..struct _Global
  0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x78, 0x34, 0x20,  // .{.    float4x4 
  0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x3b,  // u_modelViewProj;
  0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74,  // .};..struct xlat
  0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, 0x20, 0x20,  // MtlMain_out.{.  
  0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x5f, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50,  //   float2 _entryP
  0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f, 0x74, 0x65, 0x78,  // ointOutput_v_tex
  0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f,  // coord0 [[user(lo
  0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61,  // cn0)]];.    floa
  0x74, 0x34, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x5b,  // t4 gl_Position [
  0x5b, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a,  // [position]];.};.
  0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d,  // .struct xlatMtlM
  0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f,  // ain_in.{.    flo
  0x61, 0x74, 0x33, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x5b,  // at3 a_position [
  0x5b, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b,  // [attribute(0)]];
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x61, 0x5f, 0x74, 0x65,  // .    float2 a_te
  0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62,  // xcoord0 [[attrib
  0x75, 0x74, 0x65, 0x28, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x76, 0x65,  // ute(1)]];.};..ve
  0x72, 0x74, 0x65, 0x78, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,  // rtex xlatMtlMain
  0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e,  // _out xlatMtlMain
  0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x20,  // (xlatMtlMain_in 
  0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, 0x5d, 0x2c,  // in [[stage_in]],
  0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x20, 0x5f, 0x47, 0x6c, 0x6f, 0x62, 0x61,  //  constant _Globa
  0x6c, 0x26, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x20, 0x5b, 0x5b, 0x62, 0x75, 0x66, 0x66,  // l& _mtl_u [[buff
  0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x78,  // er(0)]]).{.    x
  0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x6f,  // latMtlMain_out o
  0x75, 0x74, 0x20, 0x3d, 0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74,  // ut = {};.    out
  0x2e, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x5f,  // .gl_Position = _
  0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x2e, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65,  // mtl_u.u_modelVie
  0x77, 0x50, 0x72, 0x6f, 0x6a, 0x20, 0x2a, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x28, 0x69,  // wProj * float4(i
  0x6e, 0x2e, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x20, 0x31, 0x2e,  // n.a_position, 1.
  0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x5f, 0x65, 0x6e, 0x74,  // 0);.    out._ent
  0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f,  // ryPointOutput_v_
  0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20, 0x69, 0x6e, 0x2e, 0x61,  // texcoord0 = in.a
  0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20,  // _texcoord0;.    
  0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,  // return out;.}...
  0x02, 0x01, 0x00, 0x10, 0x00, 0x40, 0x00 };                                                      // out;.}........@.
unsigned int vs_textured_passthrough_bin_metal_size = 695;

BX_UNUSED(vs_textured_passthrough_bin_metal)
BX_UNUSED(vs_textured_passthrough_bin_metal_size)
static const uint8_t vs_textured_passthrough_bin_spirv[] = {
  0x56, 0x53, 0x48, 0x09, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x1e, 0x3e, 0x3c, 0x01, 0x00, 0x0f, 0x75,  // VSH.....o.><...u
  0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01,  // _modelViewProj..
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x14, 0x04, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00,  // ............#...
  0x01, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00,  // ......b.........
  0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c,  // ..............GL
  0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,  // SL.std.450......
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x00, 0x00,  // ................
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00,  // ......main....1.
  0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..5...>...B.....
  0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00,  // ................
  0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x21, 0x00,  // ..main........!.
  0x00, 0x00, 0x55, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x42, 0x6c, 0x6f, 0x63, 0x6b, 0x00, 0x00,  // ..UniformBlock..
  0x00, 0x00, 0x06, 0x00, 0x07, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f,  // ......!.......u_
  0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x05, 0x00,  // modelViewProj...
  0x03, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x31, 0x00,  // ..#...........1.
  0x00, 0x00, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x05, 0x00,  // ..a_position....
  0x05, 0x00, 0x35, 0x00, 0x00, 0x00, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64,  // ..5...a_texcoord
  0x30, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79,  // 0.....>...@entry
  0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, 0x67, 0x6c, 0x5f, 0x50,  // PointOutput.gl_P
  0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x42, 0x00,  // osition.......B.
  0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74,  // ..@entryPointOut
  0x70, 0x75, 0x74, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00,  // put.v_texcoord0.
  0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,  // ..H...!.........
  0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00,  // ..H...!.......#.
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......H...!.....
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0x21, 0x00,  // ..........G...!.
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x22, 0x00,  // ......G...#...".
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x21, 0x00,  // ......G...#...!.
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x31, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ......G...1.....
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x35, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ......G...5.....
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x0b, 0x00,  // ......G...>.....
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x42, 0x00, 0x00, 0x00, 0x1e, 0x00,  // ......G...B.....
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00,  // ..............!.
  0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x06, 0x00,  // ................
  0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00,  // .. .............
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06, 0x00,  // ................
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x06, 0x00,  // ................
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x20, 0x00,  // .............. .
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x19, 0x00,  // ......+.........
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1b, 0x00,  // ......+.........
  0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x18, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0b, 0x00,  // .....?.... .....
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x03, 0x00, 0x21, 0x00, 0x00, 0x00, 0x20, 0x00,  // ..........!... .
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00,  // .. ...".......!.
  0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x02, 0x00,  // ..;..."...#.....
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x24, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x20, 0x00,  // .. ...$....... .
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00,  // .. ...0.........
  0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x30, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x01, 0x00,  // ..;...0...1.....
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x34, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x09, 0x00,  // .. ...4.........
  0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x34, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x01, 0x00,  // ..;...4...5.....
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0b, 0x00,  // .. ...=.........
  0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..;...=...>.....
  0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x41, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x09, 0x00,  // .. ...A.........
  0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x41, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x03, 0x00,  // ..;...A...B.....
  0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,  // ..6.............
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00,  // ..............=.
  0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x3d, 0x00,  // ......2...1...=.
  0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x51, 0x00,  // ......6...5...Q.
  0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00,  // ......[...2.....
  0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x32, 0x00,  // ..Q...........2.
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x5d, 0x00,  // ......Q.......].
  0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x0b, 0x00,  // ..2.......P.....
  0x00, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x5d, 0x00,  // ..^...[.......].
  0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x24, 0x00, 0x00, 0x00, 0x5f, 0x00,  // ......A...$..._.
  0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x20, 0x00,  // ..#.......=... .
  0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x90, 0x00, 0x05, 0x00, 0x0b, 0x00,  // ..`..._.........
  0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x3e, 0x00,  // ..a...^...`...>.
  0x03, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x42, 0x00,  // ..>...a...>...B.
  0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00, 0x00, 0x02,  // ..6.......8.....
  0x01, 0x00, 0x10, 0x00, 0x40, 0x00 };                                                            // ....8.........@.
unsigned int vs_textured_passthrough_bin_spirv_size = 1094;

BX_UNUSED(vs_textured_passthrough_bin_spirv)
BX_UNUSED(vs_textured_passthrough_bin_spirv_size)
static const uint8_t * vs_textured_passthrough_bin_esslandroid = NULL;
unsigned int vs_textured_passthrough_bin_esslandroid_size = 0;

BX_UNUSED(vs_textured_passthrough_bin_esslandroid)
BX_UNUSED(vs_textured_passthrough_bin_esslandroid_size)
static const uint8_t * vs_textured_passthrough_bin_pssl = NULL;
unsigned int vs_textured_passthrough_bin_pssl_size = 0;

BX_UNUSED(vs_textured_passthrough_bin_pssl)
BX_UNUSED(vs_textured_passthrough_bin_pssl_size)
static const uint8_t * vs_textured_passthrough_bin_esslnacl = NULL;
unsigned int vs_textured_passthrough_bin_esslnacl_size = 0;

BX_UNUSED(vs_textured_passthrough_bin_esslnacl)
BX_UNUSED(vs_textured_passthrough_bin_esslnacl_size)
