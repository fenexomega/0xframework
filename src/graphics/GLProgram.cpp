#include "GLProgram.h"

GLProgram::GLProgram()
{
    this->programID = glCreateProgram();
}

void GLProgram::AttachShader(GLShader* shdr)
{
    shaderList.push_back(shdr);
    glAttachShader(programID,shdr->getShaderId());

}

void GLProgram::Use()
{
    glUseProgram(programID);
}

void GLProgram::Link()
{
    glLinkProgram(programID);
}

GLint GLProgram::getAttrib(std::string attrib)
{
    // Não esquecer de habilitar os attribs com
    // glEnableVertexAttribArray(attrib)
    return glGetAttribLocation(programID,attrib.c_str());
}

GLint GLProgram::EnableAttrib(std::string attrib)
{
    GLint num = getAttrib(attrib);
    if(num == -1)
    {
        std::cerr << "Couldn't get " << attrib << " attrib" << std::endl;
        return num;
    }
    glEnableVertexAttribArray(num);
    return num;

}

GLint GLProgram::DisableAttrib(std::string attrib)
{
    GLint num = getAttrib(attrib);
    if(num == -1)
    {
        std::cerr << "Couldn't open " << attrib << " attrib" << std::endl;
        return num;
    }
    std::cout << attrib << " = " << num << std::endl;
    glDisableVertexAttribArray(num);
    return num;

}


void GLProgram::BindFragDataLocation(std::string frag,GLuint colorNumber)
{
    glBindFragDataLocation(programID,colorNumber,frag.c_str());
}

GLProgram::~GLProgram()
{
    for(auto i : shaderList)
    {
        glDetachShader(programID,i->getShaderId());
        delete i;
    }
    shaderList.clear();
    glDeleteProgram(programID);
}
