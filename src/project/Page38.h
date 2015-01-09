#ifndef PAGE38_H
#define PAGE38_H

#include "Game.h"
#include "graphics/GLProgram.h"
#include <glm/glm.hpp>


class Page38 : public Game
{
private:
    glm::mat4 proj,view;
    GLProgram *program;
    GLuint vbo,vao,ebo;
    GLuint blockIndex,ubo;
public:
    Page38();
    ~Page38();

    // Game interface
    void update();
    void draw();
    void pause();
    void init();
    void dispose();
};

#endif // PAGE38_H
