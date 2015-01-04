#include "graphics/SysGraphics.h"

SysGraphics::SysGraphics()
{

}

SysGraphics::~SysGraphics()
{

}



bool SysGraphics::init()
{
    LOG("Graphics Sys Initializing");
    bool status = true;
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        status = false;

    return status;
}

bool SysGraphics::dispose()
{
    LOG("Graphics Sys Disposing");
    SDL_Quit();
    return true;
}

void SysGraphics::getGlInfo()
{
    std::vector<GLchar *> glinfo;

    glinfo.push_back((GLchar *)glGetString(GL_VERSION));
    glinfo.push_back((GLchar *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    glinfo.push_back((GLchar *)glGetString(GL_VENDOR));
    glinfo.push_back((GLchar *)glGetString(GL_RENDERER));

    LOG("=========================");
    for(auto i : glinfo)
    {
        LOG(i);
    }
    LOG("=========================");

}

