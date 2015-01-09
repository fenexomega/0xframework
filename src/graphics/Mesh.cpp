#include "Mesh.h"
#include "utils/Logger.h"
#include <glm/gtc/type_ptr.hpp>

GLuint Mesh::modelAttrib;

glm::mat4 Mesh::getModel() const
{
    return model;
}

void Mesh::setModel(const glm::mat4 &value)
{
    model = value;
}

GLuint Mesh::getModelAttrib()
{
    return modelAttrib;
}

void Mesh::setModelAttrib(const GLuint &value)
{
    modelAttrib = value;
}

void Mesh::update()
{
}

Mesh::Mesh(GLfloat *vertex, GLuint _nbrOfElem ,glm::vec4 _color )
    : nbrOfElem(_nbrOfElem), color(_color)
{
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    glGenBuffers(1,&vbo[VB_POSITION]);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_POSITION]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfElem*(3*sizeof(GLfloat)),vertex,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0);

    glGenBuffers(1,&vbo[VB_COLOR]);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLOR]);
    glBufferData(GL_ARRAY_BUFFER,(4*sizeof(GLfloat)),glm::value_ptr(color),GL_STATIC_DRAW);

    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,4*sizeof(GLfloat),0);

    glBindVertexArray(0);

    model = glm::mat4(1);

}

Mesh::~Mesh()
{
    glDeleteBuffers(1,&vbo[VB_POSITION]);
    glDeleteBuffers(1,&ebo);
    glDeleteVertexArrays(1,&vao);
}

const void Mesh::draw()
{
    glBindVertexArray(vao);
    glUniformMatrix4fv(modelAttrib,1,GL_FALSE,glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES,0,nbrOfElem);
    glBindVertexArray(0);

}

