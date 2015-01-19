#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
using glm::vec3;

namespace ox
{
class Transform
{
private:
    vec3 m_pos;
    vec3 m_rot;
    vec3 m_scale;
    glm::mat4 m_model;
public:

    Transform(vec3 _m_pos = vec3(),
    vec3 _m_rot = vec3(),
    vec3 _m_scale = vec3(1,1,1));

//    glm::mat4 getModel() const;

    glm::mat4 getMatrix();

    Transform& rotate(float angle,float x,float y,float z);

    Transform& rotate(float angle,glm::vec3 vec);

    Transform& translate(float x,float y,float z);

    Transform& translate(glm::vec3 vec);

    Transform& scale(float x,float y,float z);

    Transform& scale(glm::vec3 vec);

    Transform& clear();

    ~Transform();
    vec3& pos();
    void setPos(const vec3 &pos);
    vec3& rot();
    void setRot(const vec3 &rot);
    vec3& scale();
    void setScale(const vec3 &scale);
};
}
#endif // TRANSFORM_H
