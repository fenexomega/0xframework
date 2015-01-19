#include "Sprite.h"

#include "graphics/Window.h"

Sprite::Sprite(glm::vec3 pos, std::string TextureFile)
{
    ox::Window win;
    tex = new ox::Texture(TextureFile);
    w = tex->getW()/win.getWidth();
    h = tex->getH()/win.getHeight();

}

Sprite::~Sprite()
{
    delete tex;
}

