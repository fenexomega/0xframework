#version 330

out vec3 Color;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    Color = vec3(1.0,1.0,0);
    gl_Position =  proj * view * model * vec4(position,1.0);

}
