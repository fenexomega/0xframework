#include "Window.h"
using namespace ox;


SDL_Window *Window::SDLwindow;
SDL_GLContext Window::GLcontext;
int Window::width;
int Window::height;




int Window::getWidth()
{
    return width;
}

void Window::setWidth(int value)
{
    width = value;
}

int Window::getHeight()
{
    return height;
}

void Window::setHeight(int value)
{
    height = value;
}
void Window::CreateGlContext()
{




}

Window::Window()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,GL_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,GL_MINOR);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,SDL_TRUE);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE,8);

}

Window::~Window()
{

}

void Window::SwapBuffers()
{
    SDL_GL_SwapWindow(SDLwindow);
}

bool Window::UserWannaQuit()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    return e.type == SDL_QUIT;
}

void Window::CreateWindow(int _width, int _height, std::string title, bool isFullscreen )
{
    static int windowsFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if(SDLwindow)
        SDL_DestroyWindow(SDLwindow);

    if(GLcontext)
        SDL_GL_DeleteContext(GLcontext);

    if(isFullscreen)
        windowsFlags |=  SDL_WINDOW_FULLSCREEN;

    this->width = _width;
    this->height = _height;
    SDLwindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED
                                 ,SDL_WINDOWPOS_CENTERED,width,height,
                                 windowsFlags);


    GLcontext = SDL_GL_CreateContext(SDLwindow);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
       LOG("Couldn't Initialize Glew. Exiting");
       EXIT();
    }

    glViewport(0,0,width,height);
}

void Window::Destroy()
{
    SDL_GL_DeleteContext(GLcontext);
    SDL_DestroyWindow(SDLwindow);
}


