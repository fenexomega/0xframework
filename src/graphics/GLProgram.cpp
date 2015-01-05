#include "GLProgram.h"

#include <memory>
#include "utils/Logger.h"

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

void GLProgram::PrintActiveVertexInput()
{
    GLint maxLenght, nAttribs;
    glGetProgramiv(programID,GL_ACTIVE_ATTRIBUTES,&nAttribs);
    glGetProgramiv(programID,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,&maxLenght);
    GLchar * name = new GLchar[maxLenght];

    GLint written, size,location;
    GLenum type;
    LOG("-------------------------------------");
    LOG("PRITING ACTIVE ATTRIBUTES VARIABLES");
    LOG("-------------------------------------");
    for (int i = 0; i < nAttribs; ++i)
    {
        glGetActiveAttrib(programID,i,maxLenght, &written,&size,&type,name);
        location = glGetAttribLocation(programID,name);
        std::string sname(name);
        LOG(TOSTR(location) + " : "  + (sname));

    }
    delete name;

}

void GLProgram::PrintActiveUniforms()
{
    GLint maxLenght, nAttribs;
    glGetProgramiv(programID,GL_ACTIVE_UNIFORMS,&nAttribs);
    glGetProgramiv(programID,GL_ACTIVE_UNIFORM_MAX_LENGTH,&maxLenght);
    GLchar * name = new GLchar[maxLenght];

    GLint written, size,location;
    GLenum type;
    LOG("-------------------------------------");
    LOG("PRITING ACTIVE UNIFORMS");
    LOG("-------------------------------------");
    for (int i = 0; i < nAttribs; ++i)
    {
        glGetActiveUniform(programID,i,maxLenght, &written,&size,&type,name);
        location = glGetUniformLocation(programID,name);
        std::string sname(name);
        LOG(TOSTR(location) + " : "  + (sname));

    }
    delete name;
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
