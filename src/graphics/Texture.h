#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>


namespace ox
{
class Texture
{
private:
    unsigned int textureId;
    float w,h;
public:
    Texture(const std::string filename);
    ~Texture();
    void Bind();
    float getW() const;
    void setW(float value);
    float getH() const;
    void setH(float value);
};
}
#endif // TEXTURE_H
