#version 330

out vec4 Color;
out vec2 TexCoord;
out vec4 Normal;
out vec4 LightSource;

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec3 normal;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    mat4 trans = proj * view * model;
    TexCoord = vec2(texCoord.x,-texCoord.y);
    Color = color;
    Normal =  trans * vec4(normal,0.0);
    LightSource =  view * model * vec4(0,0,-1,0);
    gl_Position =  proj * view * model * vec4(position,1.0);

}
