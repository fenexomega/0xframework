#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include "graphics/Window.h"

void Camera::Translate(GLfloat x, GLfloat y, GLfloat z)
{

    view = glm::translate(view,glm::vec3(x,y,z));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}

Camera::Camera(glm::vec3 _eye, glm::vec3 _center, glm::vec3 _up,GLProgram *program, GLfloat FOV)
    : eye(_eye), center(_center),up(_up)
{
    projAttrib = glGetUniformLocation(program->getId(),"proj");
    viewAttrib = glGetUniformLocation(program->getId(),"view");
    view = glm::lookAt(eye,center,up);

    proj = glm::perspective(FOV,(GLfloat) Window::getWidth()/Window::getHeight(),0.1f,100.0f);

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}

Camera::~Camera()
{

}
