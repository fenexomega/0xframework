#include "graphics/Shader.h"
#include "utils/Logger.h"

using namespace ox;

const std::string Shader::ReadContentFromFile(std::string filename)
{
    std::fstream f(filename.c_str());
    if(f == NULL)
    {
        LOG("There is no file named " + filename );
        return "";

    }
    std::string content,aux;

    while(std::getline(f,aux) != NULL)
        content += "\n" + aux;


    return content;
}

Shader::Shader(std::string _filename,GLenum shaderType) : filename(_filename)
{
    this->shaderID = glCreateShader(shaderType);
    compilationErrors = NULL;
    std::string shaderSrc = ReadContentFromFile(filename);
    const GLchar * src = shaderSrc.c_str();
    glShaderSource(shaderID,1,&src ,0);
    glCompileShader(shaderID);
    ReadErrors();

}

void Shader::ReadErrors()
{
    GLint result;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    if( GL_FALSE == result)
    {
        GLint logLength;
        glGetShaderiv(shaderID,GL_INFO_LOG_LENGTH,&logLength);
        if( logLength > 0)
        {
            compilationErrors = new char[logLength];
            glGetShaderInfoLog(shaderID,logLength,NULL,compilationErrors);
            LOG("ERRORS:");
            LOG(compilationErrors);
        }
        return;
    }
    else
    {
        LOG( filename + " compilled OK " );
    }

}


Shader::~Shader()
{
    glDeleteShader(shaderID);
    if(!compilationErrors)
        delete compilationErrors;
}
