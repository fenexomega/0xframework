#version 330
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texcoords;

out vec4 Color;
out vec2 TexCoord;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    TexCoord = texcoords;
    Color = color;
    gl_Position =  proj * view * model * vec4(position,1.0);

}
