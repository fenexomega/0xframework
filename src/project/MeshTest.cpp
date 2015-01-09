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

//    view  = glm::lookAt();
//    proj  = glm::perspective(45.0f,(float)  Window::getWidth()/Window::getHeight(),0.1f,100.0f);

    glEnable(GL_DEPTH_TEST);

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


    GLuint modelAttrib = glGetUniformLocation(program->getId(),"model");

    meshes.push_back(new Mesh(positions,3,glm::vec4(1,0,0,1)));
    meshes.push_back(new Mesh(positions2,3,glm::vec4(0,1,1,1)));
    meshes[0]->setModelAttrib(modelAttrib);

    cam = new Camera(glm::vec3(0,0.5f,-2.0f),
                     glm::vec3(0,0,0),
                     glm::vec3(0,1,0),program,45.0f);

    program->PrintActiveVertexInput();
    program->PrintActiveUniforms();
}

void MeshTest::update()
{
    static GLfloat i = 0;

//    cam->Translate(0.005f,0,-0.005f);
    meshes[1]->setModel(glm::translate(meshes[1]->getModel(),glm::vec3(0,0,-sin(i)/15)));
    i += 0.1f;

    for(Mesh *i : meshes)
        i->update();


}

void MeshTest::draw() 
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

