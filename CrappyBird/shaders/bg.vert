#version 330 core

in vec3 pos;
in vec2 vert_tc;

uniform mat4 pr_mat;
uniform mat4 vw_mat;

out odata
{
    vec2 uv;
    vec3 position;
} vert_out;

void main()
{
	gl_Position = pr_mat * vw_mat * vec4(pos, 1.0f);
	vert_out.uv = vert_tc.xy;
    vert_out.position = (vw_mat * vec4(pos, 1.0f)).xyz;
}
