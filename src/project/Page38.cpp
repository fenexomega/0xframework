#include "Page38.h"

#include "graphics/Window.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
         1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
         1.0f,-1.0f, 1.0f, 0.0f, 0.0f
    };

    GLuint elements[] =
    {
        0,1,2,
        2,3,0
    };

    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW);

    GLuint ebo;
    glGenBuffers(1,&ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);


    program = new GLProgram();
    program->AttachShader(new GLShader("vertexPage38.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new GLShader("fragmentPage38.glsl",GL_FRAGMENT_SHADER));
    program->BindFragDataLocation("finalColor",0);

    program->Link();
    program->Use();

    program->EnableAttrib("position");
    program->EnableAttrib("TexCoord");

    glVertexAttribPointer(0 , 2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),0);
    glVertexAttribPointer(1 , 3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(void*)(2*sizeof(GLfloat)));
    program->PrintActiveVertexInput();
    program->PrintActiveUniforms();
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
}
