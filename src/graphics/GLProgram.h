#ifndef GLPROGRAM_H
#define GLPROGRAM_H


#include "graphics/GLShader.h"
#include <vector>

class GLProgram
{
private:
    GLuint programID;
    std::vector<GLShader *> shaderList;
public:
    GLProgram();

    void AttachShader(GLShader *shdr);

    void Use();

    void Link();

    GLint getAttrib(std::string attrib);

    GLint EnableAttrib(std::string attrib);

    GLint DisableAttrib(std::string attrib);



    void BindFragDataLocation(std::string frag,GLuint colorNumber);

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

    ~GLProgram();

};

#endif // GLPROGRAM_H
