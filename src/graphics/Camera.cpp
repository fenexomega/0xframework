#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "graphics/Window.h"


#define TORAD(x) ((3.1415f*(x))/180.0f)
#define ABS(x)   (x) < 0 ? -(x) : (x)

std::ostream& operator<<(std::ostream& os, glm::vec3 vec)
{

    return os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
}

void Camera::Translate(GLfloat x, GLfloat y, GLfloat z)
{

    view = glm::translate(view,glm::vec3(x,y,z));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}

void Camera::Translate(glm::vec3 vec)
{

    view = glm::translate(view,vec);

    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}


void Camera::Rotate(GLfloat angle, glm::vec3 rot)
{
    rotation += angle;
//    LOG(TOSTR(rotation));
//    LOG("sin("+TOSTR(rotation)+")"+" = " + TOSTR(sin(rotation)));
//    LOG("cos("+TOSTR(rotation)+")"+" = " + TOSTR(cos(rotation)));

        view = glm::rotate(view,angle,rot);
//    eye = glm::rotate(eye,angle,rot);
//    center = glm::rotate(center,angle,rot);
//    view = glm::lookAt(eye,center,up);
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}

void Camera::Move(GLfloat right, GLfloat up, GLfloat front )
{
    glm::vec3 distance(-front*(sin(rotation)) + right*(cos(rotation)) ,up,
                       front*(cos(rotation)) + right*(sin(rotation)) );
    //+ right*(ABS(sin(TORAD(rotation)))))
    Translate(distance);
}

Camera::Camera(glm::vec3 _eye, glm::vec3 _center, glm::vec3 _up,Program *program, GLfloat FOV)
    : eye(_eye), center(_center),up(_up)
{
    projAttrib = glGetUniformLocation(program->getId(),"proj");
    viewAttrib = glGetUniformLocation(program->getId(),"view");
    modelAttrib = glGetUniformLocation(program->getId(),"model");

    view = glm::lookAt(eye,center,up);
    rotation = 0;

    proj = glm::perspective(FOV,(GLfloat) Window::getWidth()/Window::getHeight(),0.1f,100.0f);

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}



Camera::~Camera()
{

}
