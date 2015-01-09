#version 330

out vec4 Color;

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    Color = color;
    gl_Position =  proj * view * model * vec4(position,1.0);

}
