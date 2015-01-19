#version 330
in vec4 Color;
in vec2 TexCoord;

uniform sampler2D sampler;

out vec4 finalColor;

void main()
{
    finalColor = texture(sampler,TexCoord) * Color;
}
