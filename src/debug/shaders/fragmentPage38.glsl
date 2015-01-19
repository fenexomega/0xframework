#version 330
in vec2 texCoord;
out vec4 finalColor;

uniform blobSettings
{
    vec4 InnerColor;
    vec4 OuterColor;
    float RadiusInner;
    float RadiusOuter;
}BS;

void main()
{
    float dx = texCoord.x - 0.5;
    float dy = texCoord.y - 0.5;
    float dist = sqrt(dx*dx + dy*dy);

    finalColor = mix(BS.InnerColor,BS.OuterColor,
                 smoothstep(BS.RadiusInner,BS.RadiusOuter,dist));
}
