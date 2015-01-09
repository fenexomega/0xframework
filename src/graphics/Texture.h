#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>



class Texture
{
private:
    unsigned int textureId;
public:
    Texture(const std::string filename);
    ~Texture();
    void Bind();
};

#endif // TEXTURE_H
