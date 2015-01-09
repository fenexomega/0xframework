#ifndef MESH_H
#define MESH_H

#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.h"

#define MAX_VBS 16


class Mesh
{
private:
    GLuint vao,ebo;
    GLuint nbrOfElem;
    glm::mat4 model;
    static GLuint modelAttrib;
    Texture * texture;
    glm::vec4 color;

    enum
    {
        VB_POSITION,
        VB_COLOR,
        VB_ELEMENTS
    };

    GLuint vbo[MAX_VBS];

public:
    Mesh(GLfloat *vertex, GLuint _nbrOfElem , glm::vec4 _color);
    ~Mesh();

    void const draw();
    glm::mat4 getModel() const;
    void setModel(const glm::mat4 &value);
    static GLuint getModelAttrib();
    static void setModelAttrib(const GLuint &value);
    void update();
};

#endif // MESH_H
