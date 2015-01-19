#version 330
in vec4 Color;
in vec2 TexCoord;
in vec4 Normal;
in vec4 LightSource;

out vec4 finalColor;

uniform sampler2D sampler;

void main()
{
    finalColor = texture(sampler,TexCoord)*Color
        * clamp(dot(LightSource,Normal),0.0,1.0);
}
