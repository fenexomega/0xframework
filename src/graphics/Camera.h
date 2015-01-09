#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

#include "graphics/GLProgram.h"

using glm::vec3;
using glm::mat4;

class Camera
{
private:
    vec3 eye,center,up;
    mat4 view,proj;
    GLuint projAttrib,viewAttrib;
    GLfloat rotation; //in rads
public:
    void Translate(GLfloat x, GLfloat y,GLfloat z);
    Camera(vec3 _eye, vec3 _center, vec3 _up, GLProgram *program, GLfloat FOV);
    ~Camera();
};

#endif // CAMERA_H
