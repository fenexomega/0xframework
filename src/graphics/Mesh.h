#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.h"
#include "Transform.h"

#define MAX_VBS 16


class Mesh
{
private:
    GLuint vao;
    GLuint nbrOfVertex,nbrOfElements;
    static GLuint modelAttrib;
    Texture * texture;
    Transform transform;
    glm::mat4 model;
    std::vector<GLfloat> color;

    enum
    {
        VB_POSITION,
        VB_COLOR,
        VB_ELEMENTS,
        VB_TEXTURE_COORDS,

        VB_BUFFERS
    };

    GLuint vbo[MAX_VBS];

public:
    Mesh(std::vector<GLfloat> &vertex, std::vector<GLfloat> &_color,
         std::vector<GLuint> &elements,std::vector<GLfloat>& textureCoords,std::string texturefile);
    Mesh(std::string filename,std::string texturefile, glm::vec4 color);
    ~Mesh();
    void const draw();
    static GLuint getModelAttrib();
    static void setModelAttrib(const GLuint &value);
    void update();

    Transform getTransform() const;
    void setTransform(const Transform &value);
};

#endif // MESH_H
