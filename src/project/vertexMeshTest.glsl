#version 330

out vec4 Color;
out vec2 TexCoord;

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    TexCoord = vec2(texCoord.x,-texCoord.y);
    Color = color;
    gl_Position =  proj * view * model * vec4(position,1.0);

}
