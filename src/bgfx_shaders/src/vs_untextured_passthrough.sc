$input a_position

#include <bgfx_shader.shh>

void  main() {
	gl_Position = mul(u_modelViewProj, vec4(a_position, 0.0, 1.0) );
	}
