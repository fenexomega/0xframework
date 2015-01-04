#ifndef GLSHADER_H
#define GLSHADER_H

//OPENGL HEADERS
#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>


class GLShader
{
private:
    std::string filename;
    GLchar * compilationErrors;
    unsigned int shaderID;

    void ReadErrors();
    const std::string ReadContentFromFile(std::string filename);

public:
    GLShader(std::string filename,GLenum shaderType);

    const int getShaderId()
    {
        return shaderID;
    }

    const std::string getCompilationErrors()
    {
        return compilationErrors;
    }

    ~GLShader();
};

#endif // GLSHADER_H
