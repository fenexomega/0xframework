#version 330
in vec4 Color;
in vec2 TexCoord;

out vec4 finalColor;

uniform sampler2D sampler;

void main()
{
    finalColor = texture2D(sampler,TexCoord)*Color;
}
