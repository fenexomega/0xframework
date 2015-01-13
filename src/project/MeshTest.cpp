#include "MeshTest.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphics/Window.h"
#include "input/sysInput.h"

using std::vector;

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
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
//    vector<GLfloat> positions = {
//        0.0f,1.0f,0.0f,
//        1.0f,0.0f,0.0f,
//        -1.0f,0.0f,0.0f
//    };


//    vector<GLfloat> positions2 = {
//        0.0f,1.0f,0.5f,
//        1.0f,0.0f,0.5f,
//        -1.0f,0.0f,0.5f
//    };





//   vector<GLfloat> color = {
//       0.0f,1.0f,0.0f,1.0f,
//       1.0f,0.0f,0.0f,1.0f,
//       1.0f,0.0f,0.0f,1.0f
//   };

//   vector<GLfloat> color2 = {
//       0.0f,1.0f,0.5f,1.0f,
//       1.0f,0.0f,0.5f,1.0f,
//       1.0f,0.0f,0.5f,1.0f,
//   };

    vector<GLfloat>  pos = {
         10.0f,-5.0f,2.0f,
        -10.0f,-5.0f,2.0f,
        -10.0f, 5.0f,2.0f,
         10.0f, 5.0f,2.0f,
     };


   vector<GLfloat>  color = {
        0.7f,0.3f,0.1f,1.0f,
        0.7f,0.3f,0.1f,1.0f,
        0.7f,0.3f,0.1f,1.0f,
        0.7f,0.3f,0.1f,1.0f,
    };

   vector<GLfloat> texcoord = {
       6.0f,6.0f,
       0.0f,6.0f,
       0.0f,0.0f,
       6.0f,0.0f
   };

   vector<GLuint> elements = {
        0,1,2,
        2,3,0
   };


    program = new Program();
    program->AttachShader(new GLShader("vertexMeshTest.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new GLShader("fragmentMeshTest.glsl",GL_FRAGMENT_SHADER));
    program->BindFragDataLocation("finalColor",0);

    program->Link();
    program->Use();


    GLuint modelAttrib = program->getUniformLocation("model");

//    meshes.push_back(new Mesh(positions,color));
//    meshes.push_back(new Mesh(positions2,color2));
//    meshes.push_back(new Mesh("cube.obj","bricks.png",glm::vec4(1,1,1,1)));
    meshes.push_back(new Mesh("monkey3.obj","bricks.png",glm::vec4(1,1,1,1)));
    meshes.push_back(new Mesh(pos,color,elements,texcoord,"bricks.png"));
//    meshes.push_back(new Mesh("steve.obj","steve.png",glm::vec4(1,1,1,1)));
//      meshes.push_back(new Mesh("ghv.obj","ghv-RGBA.png",glm::vec4(1,1,1,1)));
    meshes.at(0)->setModelAttrib(modelAttrib);

    cam = new Camera(glm::vec3(0,0.5f,-5.5f),
                     glm::vec3(0,0,0),
                     glm::vec3(0,1,0),program,45.0f);

//    program->PrintActiveVertexInput();
//    program->PrintActiveUniforms();

    Transform trans;
    trans.rotate(0.01f,0,1,0);

    meshes[0]->setTransform(trans);



}

void MeshTest::update()
{
    static GLfloat i = 0;

    //    cam->Translate(0.005f,0,-0.005f);
    i += 0.1f;



    for(Mesh *i : meshes)
        i->update();

    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        cam->Move(0,0,-0.05f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        cam->Move(0,0,0.05f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        cam->Move(-0.05f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        cam->Move(0.05f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_SPACE))
        cam->Move(0,-0.05f,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_LCTRL))
        cam->Move(0,0.05,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_Q))
        cam->Rotate(0.1f,glm::vec3(0,1,0));
    if(sysInput::isKeyPressed(SDL_SCANCODE_E))
        cam->Rotate(-0.1f,  glm::vec3(0,1,0));


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

