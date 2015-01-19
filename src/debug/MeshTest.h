#ifndef MESHTEST_H
#define MESHTEST_H

#include "project/Game.h"
#include <iostream>
#include "graphics/Program.h"
#include "graphics/Window.h"
#include <glm/glm.hpp>
#include "graphics/Mesh.h"
#include "graphics/Camera.h"

using namespace ox;


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
    void update(double delta);
    void draw(double delta);

	void pause() ;

	void init() ;

	void dispose() ;



    // Game interface
public:

};

#endif
