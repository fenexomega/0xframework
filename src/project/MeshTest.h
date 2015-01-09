#ifndef MESHTEST
#define MESHTEST

#include "Game.h"
#include <iostream>
#include "graphics/GLProgram.h"
#include "graphics/Window.h"
#include <glm/glm.hpp>
#include "graphics/Mesh.h"


class MeshTest : public Game
{
private:
 	GLuint vao;
	GLuint vbo;
    GLuint ebo;
    GLProgram *program;
    glm::mat4 view,proj;
    std::vector<Mesh *> meshes;
    GLuint projAttrib,viewAttrib;
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
