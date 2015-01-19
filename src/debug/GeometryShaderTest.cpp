#include "GeometryShaderTest.h"

#include "graphics/Window.h"
#include "input/sysInput.h"

GeometryShaderTest::GeometryShaderTest()
{

}

GeometryShaderTest::~GeometryShaderTest()
{

}



void GeometryShaderTest::init()
{
    Window win;
    win.CreateWindow(1000,600,"Geometry Shader Test");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    program = new Program();
    program->AttachShader(new Shader("vertGeometry.glsl",GL_VERTEX_SHADER));
    program->AttachShader(new Shader("fragGeometry.glsl",GL_FRAGMENT_SHADER));
    program->Link();
    program->Use();
    program->BindFragDataLocation("finalColor",0);
    cam = new Camera(glm::vec3(0,0,2),glm::vec3(0,0,0)
                     ,glm::vec3(0,1,0),program,45.0f);

    meshes.push_back(new Mesh("monkey3.obj","bricks.png",glm::vec4(1,1,1,1)));
    GLuint modelAttrib = program->getUniformLocation("model");
    meshes.at(0)->setModelAttrib(modelAttrib);

    Transform trans;
    trans.rotate(0.01f,vec3(0,1,0));
    meshes.at(0)->setTransform(trans);

    program->PrintActiveVertexInput();
}

void GeometryShaderTest::update(double delta)
{
    for(auto i : meshes)
        i->update();

    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        cam->Move(0,0,0.1f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        cam->Move(0,0,-0.1f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        cam->Move(0.1f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        cam->Move(-0.1f,0,0.);


}

void GeometryShaderTest::pause()
{
}

void GeometryShaderTest::draw()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto i : meshes) {
        i->draw();
    }
}

void GeometryShaderTest::dispose()
{
}
