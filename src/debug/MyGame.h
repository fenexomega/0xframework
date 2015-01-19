#ifndef MYGAME
#define MYGAME

#include "project/Game.h"
#include <iostream>
#include "graphics/Program.h"
#include "graphics/Window.h"
#include <glm/glm.hpp>

using namespace ox;

class MyGame : public Game
{
private:
 	GLuint vao;
	GLuint vbo;
    GLuint ebo;
    Program *program;
    glm::mat4 view,proj;

protected:

public:

    MyGame();
	virtual ~MyGame();
    void update() ;

	void draw() ;

	void pause() ;

	void init() ;

	void dispose() ;


};

#endif
