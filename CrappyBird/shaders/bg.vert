#version 330 core

in vec3 pos;
//layout (location = 1) in vec4 tcs;

uniform mat4 pr_mat;
uniform mat4 vw_mat;

void main()
{
	gl_Position = pr_mat * vw_mat * vec4(pos, 1.0f);
	// Debug pos
	//vec4 test = pr_mat[0];
	//gl_Position = vec4(pos, 1.0f);
}
