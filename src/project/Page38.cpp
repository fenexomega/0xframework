#include "Page38.h"

#include "graphics/Window.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <algorithm>

Page38::Page38()
{

}

Page38::~Page38()
{

}

void Page38::init()
{
    Window win;
    win.CreateWindow(1000,700,"Page38");
    glEnable(GL_DEPTH_TEST);

    view  = glm::lookAt(glm::vec3(0,0,-4.0f),
                                  glm::vec3(0,0,0),
                                  glm::vec3(0,1,0));
    proj  = glm::perspective(45.0f,(float)  Window::getWidth()/Window::getHeight(),0.1f,100.0f);


    GLfloat vertex[] = {
         1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f,-1.0f, 0.0f, 0.0f,
         1.0f,-1.0f, 1.0f, 0.0f,
    };

    GLuint elements[] =
    {
        0,1,2,
        2,3,0
    };

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW);

    glGenBuffers(1,&ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);


    program = new Program();
    program->AttachShader(new GLShader("vertexPage38.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new GLShader("fragmentPage38.glsl",GL_FRAGMENT_SHADER));
    program->BindFragDataLocation("finalColor",0);

    program->Link();
    program->Use();

    program->EnableAttrib("position");
    program->EnableAttrib("TexCoord");

    glVertexAttribPointer(0 , 2,GL_FLOAT,GL_FALSE,4*sizeof(GLfloat),0);
    glVertexAttribPointer(1 , 2,GL_FLOAT,GL_FALSE,4*sizeof(GLfloat),(void*)(2*sizeof(GLfloat)));
    program->PrintActiveVertexInput();
    program->PrintActiveUniforms();

    //THIS IS NEW
    blockIndex = glGetUniformBlockIndex(program->getId(),"blobSettings");
    GLint blocksize;
    glGetActiveUniformBlockiv(program->getId(),blockIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&blocksize);
    GLubyte * blockbuffer = new GLubyte[blocksize];
    const GLchar *names[]  = {"InnerColor","OuterColor","RadiusInner","RadiusOuter"};
    GLuint indices[4];
    glGetUniformIndices(program->getId(),4,names,indices);
    GLint offset[4];
    glGetActiveUniformsiv(program->getId(),4,indices,GL_UNIFORM_OFFSET,offset);
    GLfloat InnerColor[] = {1.0f,1.0f,0.75f,1.0f};
    GLfloat OuterColor[] = {0.0f,0.0f,0.0f,1.0f};
    GLfloat InnerRadius = 0.25f, OuterRadius = 0.45f;

    //Colocar os dados dentro da var

    memcpy(blockbuffer + offset[0],InnerColor,4*sizeof(GLfloat));
    memcpy(blockbuffer + offset[1],OuterColor,4*sizeof(GLfloat));
    memcpy(blockbuffer + offset[2],&InnerRadius,1*sizeof(GLfloat));
    memcpy(blockbuffer + offset[3],&OuterRadius,1*sizeof(GLfloat));


    glGenBuffers(1,&ubo);
    glBindBuffer(GL_UNIFORM_BUFFER,ubo);
    glBufferData(GL_UNIFORM_BUFFER,blocksize,blockbuffer,GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER,blockIndex,ubo);
}

void Page38::update()
{
    GLuint projAttrib = glGetUniformLocation(program->getId(),"proj");
    GLuint viewAttrib = glGetUniformLocation(program->getId(),"view");

//    view = glm::rotate(view,0.05f,glm::vec3(0,1,0));

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}



void Page38::pause()
{
}

void Page38::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}

void Page38::dispose()
{
    delete program;
    glDeleteBuffers(1,&ebo);
    glDeleteBuffers(1,&vbo);
    glDeleteBuffers(1,&ubo);
    glDeleteVertexArrays(1,&vao);

}
