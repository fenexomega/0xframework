#include "MeshTest.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics/Window.h"

MeshTest::MeshTest()
{

}

MeshTest::~MeshTest()
{
	
}

void MeshTest::init()
{



    Window win;
    win.CreateWindow(1000,600,"MyGame");

    view  = glm::lookAt(glm::vec3(0,0.5f,-2.0f),
                                  glm::vec3(0,0,0),
                                  glm::vec3(0,1,0));
    proj  = glm::perspective(45.0f,(float)  Window::getWidth()/Window::getHeight(),0.1f,100.0f);

    GLfloat positions[] = {
        0.0f,1.0f,0.0f,
        1.0f,0.0f,0.0f,
        -1.0f,0.0f,0.0f
    };


    GLfloat positions2[] = {
        0.0f,1.0f,0.5f,
        1.0f,0.0f,0.5f,
        -1.0f,0.0f,0.5f
    };


    program = new GLProgram();
    program->AttachShader(new GLShader("vertexMeshTest.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new GLShader("fragmentMeshTest.glsl",GL_FRAGMENT_SHADER));
    program->BindFragDataLocation("finalColor",0);

    program->Link();
    program->Use();

    projAttrib = glGetUniformLocation(program->getId(),"proj");
    viewAttrib = glGetUniformLocation(program->getId(),"view");
    GLuint modelAttrib = glGetUniformLocation(program->getId(),"model");

//    GLuint posAttrib = program->EnableAttrib("position");
    //GLuint colorAttrib = program->EnableAttrib("color");

//    glVertexAttribPointer(posAttrib,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0);
    //glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(void *)(2*sizeof(GLfloat)));
    meshes.push_back(new Mesh(positions,3));
    meshes.push_back(new Mesh(positions2,3));
    meshes[0]->setModelAttrib(modelAttrib);

    program->PrintActiveVertexInput();
    program->PrintActiveUniforms();
}

void MeshTest::update()
{



    meshes[1]->setModel(glm::rotate(meshes[1]->getModel(),0.05f,glm::vec3(0,1,0)));

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

    for(Mesh *i : meshes)
        i->update();


}

void MeshTest::draw() 
{

	glClear(GL_COLOR_BUFFER_BIT);	
	glClearColor(0,0,0,1);
    for(auto i : meshes)
        i->draw();

}

void MeshTest::pause()
{

}



void MeshTest::dispose()
{
    delete program;
    for(auto i : meshes)
        delete i;
}

