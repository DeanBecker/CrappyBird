#version 330 core

in vec3 pos;
in vec2 vert_tc;

uniform bool inverted;
uniform mat4 pr_mat;
uniform mat4 vw_mat;
uniform mat4 mo_mat;

out odata
{
    vec2 uv;
    vec3 position;
} vert_out;

void main()
{
    vec3 adjPos = pos;
	if (inverted)
	{
        adjPos.y = (adjPos.y * -1) - 8.0f;
	}
	gl_Position = pr_mat * vw_mat * mo_mat * vec4(adjPos, 1.0f);
	vert_out.uv = vert_tc;
	vert_out.position = (vw_mat * vec4(adjPos, 1.0f)).xyz;
}
