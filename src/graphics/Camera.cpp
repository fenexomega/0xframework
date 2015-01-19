#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "graphics/Window.h"

using namespace ox;


#define TORAD(x) ((3.1415f*(x))/180.0f)
#define ABS(x)   (x) < 0 ? -(x) : (x)

std::ostream& operator<<(std::ostream& os, glm::vec3 vec)
{

    return os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
}

void Camera::Update()
{
    view = glm::lookAt(eye,center,up);
    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));
}

void Camera::Translate(GLfloat x, GLfloat y, GLfloat z)
{
    auto vec = glm::vec3(x,y,z);
    eye += vec;
    center += vec;

}

void Camera::Translate(glm::vec3 vec)
{
    eye += vec;
    center += vec;
}


void Camera::Rotate(GLfloat angle, glm::vec3 rot)
{
    rotation += angle;
    center = vec3(eye.x + 1*sin(rotation),
                  eye.y,
                  eye.z - 1*cos(rotation));

}

void Camera::Move(GLfloat right, GLfloat up, GLfloat front )
{
    glm::vec3 distance(-front*(sin(rotation)) + right*(cos(rotation)) ,up,
                       front*(cos(rotation)) + right*(sin(rotation)) );
    Translate(distance);
}

Camera::Camera(glm::vec3 _eye, glm::vec3 _center, glm::vec3 _up,Program *program, GLfloat FOV)
    : eye(_eye), center(_center),up(_up)
{
    projAttrib = glGetUniformLocation(program->getId(),"proj");
    viewAttrib = glGetUniformLocation(program->getId(),"view");

    view = glm::lookAt(eye,center,up);
    rotation = 0;

    proj = glm::perspective(FOV, Window::getWidth()/(GLfloat)Window::getHeight(),0.1f,100.0f);

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}



Camera::~Camera()
{

}
