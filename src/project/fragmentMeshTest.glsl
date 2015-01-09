#version 330
in vec4 Color;
out vec4 finalColor;

void main()
{
    finalColor = mix(Color,vec4(0.2),
                     vec4(0.5)
                     );
}
