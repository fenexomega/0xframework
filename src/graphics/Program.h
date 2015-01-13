#ifndef PROGRAM_H
#define PROGRAM_H


#include "graphics/GLShader.h"
#include <vector>

class Program
{
private:
    GLuint programID;
    std::vector<GLShader *> shaderList;
public:
    Program();

    void AttachShader(GLShader *shdr);

    void Use();

    void Link();

    GLint getAttrib(std::string attrib);

    GLint EnableAttrib(std::string attrib);

    GLint DisableAttrib(std::string attrib);

    void PrintActiveVertexInput();

    void PrintActiveUniforms();

    void BindFragDataLocation(std::string frag,GLuint colorNumber);

    const GLint getUniformLocation(std::string loc) const;

    const GLuint getId()
    {
        return programID;
    }

//    std::ofstream operator<<(std::ofstream oth)
//    {
//        std::ofstream ofs;
//        ofs << programID << oth;
//        return ofs;
//    }

    ~Program();

};

#endif // GLPROGRAM_H
