#ifndef SPRITE_H
#define SPRITE_H

#include "graphics/Texture.h"

#include <glm/glm.hpp>


class Sprite
{
private:
    ox::Texture *tex;
    float w,h;
    glm::vec3 pos;
public:
    Sprite(glm::vec3 pos,std::string TextureFile);
    ~Sprite();
};

#endif // SPRITE_H
