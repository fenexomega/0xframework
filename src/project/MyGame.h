#ifndef MYGAME
#define MYGAME

#include "Game.h"
#include <iostream>
#include "graphics/GLProgram.h"
#include "graphics/Window.h"
#include <glm/glm.hpp>



class MyGame : public Game
{
private:
 	GLuint vao;
	GLuint vbo;
    GLuint ebo;
    GLProgram *program;
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
