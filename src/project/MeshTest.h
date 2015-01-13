#ifndef MESHTEST_H
#define MESHTEST_H

#include "Game.h"
#include <iostream>
#include "graphics/Program.h"
#include "graphics/Window.h"
#include <glm/glm.hpp>
#include "graphics/Mesh.h"
#include "graphics/Camera.h"


class MeshTest : public Game
{
private:
 	GLuint vao;
	GLuint vbo;
    GLuint ebo;
    Program *program;
    glm::mat4 view,proj;
    std::vector<Mesh *> meshes;
    Camera *cam;
protected:

public:

    MeshTest();
    virtual ~MeshTest();
    void update() ;

	void draw() ;

	void pause() ;

	void init() ;

	void dispose() ;


};

#endif
