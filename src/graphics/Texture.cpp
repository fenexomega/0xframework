#include "Texture.h"

#include <SDL2/SDL_image.h>
#include "utils/Logger.h"

Texture::Texture(const std::string filename)
{
    SDL_Surface *image = IMG_Load(filename.c_str());

    if(image == NULL)
    {
        LOG("Couldn't load the image " + filename + ". Quiting.");
        EXIT(-2);
    }

    glGenTextures(1,&textureId);
    glBindTexture(GL_TEXTURE_2D,textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image->w,image->h,0,GL_RGBA,GL_UNSIGNED_BYTE,image->pixels);


    SDL_FreeSurface(image);

    LOG(filename + " Loaded");
}

Texture::~Texture()
{

}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D,textureId);
}

