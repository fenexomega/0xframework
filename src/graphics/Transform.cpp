#include "Transform.h"

#include <glm/gtx/transform.hpp>

using namespace ox;


vec3 &Transform::pos()
{
    return m_pos;
}

void Transform::setPos(const vec3 &pos)
{
    m_pos = pos;
}

glm::vec3 &Transform::rot()
{
    return m_rot;
}

void Transform::setRot(const vec3 &rot)
{
    m_rot = rot;
}

glm::vec3 &Transform::scale()
{
    return m_scale;
}

void Transform::setScale(const vec3 &scale)
{
    m_scale = scale;
}

Transform::Transform(glm::vec3 _m_pos, glm::vec3 _m_rot, glm::vec3 _m_scale) :
    m_pos(_m_pos), m_rot(_m_rot), m_scale(_m_scale)
{

}

glm::mat4 Transform::getMatrix()
{
    return m_model;
}

//glm::mat4 Transform::getModel() const
//{
//    glm::mat4 posMx = glm::translate(m_pos);
//    glm::mat4 rotXMx = glm::rotate(m_rot.x,vec3(1,0,0));
//    glm::mat4 rotYMx = glm::rotate(m_rot.y,vec3(0,1,0));
//    glm::mat4 rotZMx = glm::rotate(m_rot.z,vec3(0,0,1));
//    glm::mat4 scaleMx = glm::scale(m_scale);

//    return ;
//}

Transform& Transform::rotate(float angle, float x, float y, float z)
{
    m_model = glm::rotate(m_model,angle,vec3(x,y,z));
    return *this;
}

Transform& Transform::rotate(float angle, glm::vec3 vec)
{
    m_model = glm::rotate(m_model,angle,vec);
    return *this;
}

Transform& Transform::translate(float x, float y, float z)
{
    m_model = glm::translate(m_model,vec3(x,y,z));
    return *this;
}

Transform& Transform::translate(glm::vec3 vec)
{
    m_model = glm::translate(m_model,vec);
    return *this;
}

Transform& Transform::scale(float x, float y, float z)
{
    m_model = glm::scale(m_model,vec3(x,y,z));
    return *this;
}

Transform& Transform::scale(glm::vec3 vec)
{
    m_model = glm::scale(m_model,vec);
    return *this;
}

Transform& Transform::clear()
{
    m_model = glm::mat4();
    return *this;
}



Transform::~Transform()
{

}

