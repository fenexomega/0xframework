#version 330
layout (location = 0) in vec2 position;
layout (location = 1) in vec3 TexCoord;
out vec3 texCoord;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
    texCoord = TexCoord;
    gl_Position =  vec4(position , 0.0 ,1.0);

}
