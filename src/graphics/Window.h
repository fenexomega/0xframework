#ifndef WINDOW_H
#define WINDOW_H

#include "GlobalDef.h"

#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Window
{
private:
    static SDL_Window *SDLwindow;
    static SDL_GLContext GLcontext;
    static int width, height;
    void CreateGlContext();
public:
    Window();
    ~Window();
    void SwapBuffers();
    bool UserWannaQuit();
    void CreateWindow(int width, int height, std::string title, bool isFullscreen = false);
    void Destroy();
    static int getWidth();
    static void setWidth(int value);
    static int getHeight();
    static void setHeight(int value);
};

#endif // WINDOW_H
