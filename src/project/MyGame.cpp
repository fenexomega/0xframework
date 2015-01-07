#include "MyGame.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics/Window.h"


MyGame::MyGame()
{

}

MyGame::~MyGame()
{
	
}

void MyGame::init()
{


    Window win;
    win.CreateWindow(1000,600,"MyGame");

    view  = glm::lookAt(glm::vec3(0,0.5f,-1.0f),
                                  glm::vec3(0,0,0),
                                  glm::vec3(0,1,0));
    proj  = glm::perspective(45.0f,(float)  Window::getWidth()/Window::getHeight(),0.1f,100.0f);

    GLfloat vertex[] = {
         0.0f, 0.5f, 0.5f, 0.0f, 0.0f,
         0.5f, 0.0f, 0.0f, 0.5f, 0.0f,
        -0.5f, 0.0f, 0.0f, 0.0f, 0.5f,

    };

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW);

    program = new GLProgram();
    program->AttachShader(new GLShader("vertex.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new GLShader("fragment.glsl",GL_FRAGMENT_SHADER));
    program->BindFragDataLocation("finalColor",0);

    program->Link();
    program->Use();

    GLuint posAttrib = program->EnableAttrib("position");
    GLuint colorAttrib = program->EnableAttrib("color");

    glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),0);
    glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(void *)(2*sizeof(GLfloat)));

    program->PrintActiveVertexInput();
    program->PrintActiveUniforms();
}

void MyGame::update()
{


    GLuint projAttrib = glGetUniformLocation(program->getId(),"proj");
    GLuint viewAttrib = glGetUniformLocation(program->getId(),"view");

    view = glm::rotate(view,0.05f,glm::vec3(0,1,0));

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));



}

void MyGame::draw() 
{

	glClear(GL_COLOR_BUFFER_BIT);	
	glClearColor(0,0,0,1);
	
    glDrawArrays(GL_TRIANGLES,0,3);
	
}

void MyGame::pause()
{

}



void MyGame::dispose()
{
    delete program;

}

