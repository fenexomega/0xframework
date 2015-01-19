#include "Mesh.h"

#include <glm/gtc/type_ptr.hpp>

#include "utils/Logger.h"
#include "io/Obj_Loader.h"
using namespace ox;




GLuint Mesh::modelAttrib;
GLint Mesh::PolygonMode;

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
    model *= transform.getMatrix();
}


Transform Mesh::getTransform() const
{
    return transform;
}

void Mesh::setTransform(const Transform &value)
{
    model = model*transform.getMatrix();
    transform = value;
}



Mesh::Mesh(std::vector<GLfloat> &vertex , std::vector<GLuint> &elements, std::vector<GLfloat>& textureCoords ,
           std::string texturefile, std::vector<GLfloat> &color, std::vector<GLfloat> &normal)
    : nbrOfVertex(vertex.size()/3), nbrOfElements(elements.size())
{
    PolygonMode = GL_TRIANGLES;
    texture = new Texture(texturefile);
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);



    glGenBuffers(VB_BUFFERS,vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_POSITION]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(3*sizeof(GLfloat)),vertex.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0); 

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vbo[VB_ELEMENTS]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,nbrOfElements*(sizeof(GLuint)),elements.data(),GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLOR]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(4*sizeof(GLfloat)),color.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,4*sizeof(GLfloat),0);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_TEXTURE_COORDS]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(2*sizeof(GLfloat)),textureCoords.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,2*sizeof(GLfloat),0);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_NORMAL]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(3*sizeof(GLfloat)),normal.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(3,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0);

    glBindVertexArray(0);

}

Mesh::Mesh(std::string filename, std::string texturefile, glm::vec4 color)
{
    PolygonMode = GL_TRIANGLES;
    IndexedModel model = OBJModel(filename).ToIndexedModel();

    texture = new Texture(texturefile);


    nbrOfVertex = model.positions.size();
    nbrOfElements = model.indices.size();

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);


    glGenBuffers(VB_BUFFERS,vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_POSITION]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(3*sizeof(GLfloat)),model.positions.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_NORMAL]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(3*sizeof(GLfloat)),model.normals.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(3,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vbo[VB_ELEMENTS]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,nbrOfElements*(sizeof(GLuint)),model.indices.data(),GL_STATIC_DRAW);

    std::vector<glm::vec4> colors;
    for(int i = 0 ; i < nbrOfVertex; ++i)
    {

        colors.push_back(color);

    }

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLOR]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(4*sizeof(GLfloat)),colors.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,4*sizeof(GLfloat),0);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_TEXTURE_COORDS]);
    glBufferData(GL_ARRAY_BUFFER,nbrOfVertex*(2*sizeof(GLfloat)),model.texCoords.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,2*sizeof(GLfloat),0);


    glBindVertexArray(0);

}

Mesh::~Mesh()
{
    delete texture;
    glDeleteBuffers(VB_BUFFERS,vbo);
    glDeleteVertexArrays(1,&vao);
}

const void Mesh::draw()
{
    glBindVertexArray(vao);
    glUniformMatrix4fv(modelAttrib,1,GL_FALSE,glm::value_ptr(model));
    texture->Bind();
    glDrawElements(PolygonMode,nbrOfElements,GL_UNSIGNED_INT,0);

    glBindVertexArray(0);

}

