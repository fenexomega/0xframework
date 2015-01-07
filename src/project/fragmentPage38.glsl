#version 330
in vec3 texCoord;
layout (location = 0) out vec4 finalColor;

uniform blobSettings
{
    vec4 InnerColor;
    vec4 OuterColor;
    float RadiusInner;
    float RadiusOuter;
};

void main()
{
    float dx = texCoord.x - 0.5;
    float dy = texCoord.y - 0.5;
    float dist = sqrt(dx*dx + dy*dy);

    finalColor = mix(InnerColor,OuterColor,
                     smoothstep(RadiusInner,RadiusOuter,dist));
}
