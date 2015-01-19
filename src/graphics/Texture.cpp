#include "Texture.h"

#include <SDL2/SDL_image.h>
#include "utils/Logger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


using namespace ox;


float Texture::getW() const
{
    return w;
}

void Texture::setW(float value)
{
    w = value;
}

float Texture::getH() const
{
    return h;
}

void Texture::setH(float value)
{
    h = value;
}
Texture::Texture(const std::string filename)
{
    SDL_Surface *image = IMG_Load(filename.c_str());

    w = image->w;
    h = image->h;


    SDL_LockSurface(image);
    if(image == NULL)
    {
        LOG("Couldn't load the image " + filename + ". Quiting.");
        EXIT();
    }

    GLenum texture_format;
    // get the number of channels in the SDL image
    auto nOfColors = image->format->BytesPerPixel;
    if (nOfColors == 4)     // contains an alpha channel
    {
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    } else if (nOfColors == 3)     // no alpha channel
    {
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }

    glGenTextures(1,&textureId);
    glBindTexture(GL_TEXTURE_2D,textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,0,texture_format,image->w,image->h,0,texture_format,GL_UNSIGNED_BYTE,image->pixels);

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

