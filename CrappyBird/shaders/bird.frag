#version 330 core

out vec4 color;

in odata
{
    vec2 uv;
    vec3 position;
} frag_in;

uniform sampler2D tex;

void main()
{
	color = vec4(texture(tex, frag_in.uv).rgb, 1.0f);
}
