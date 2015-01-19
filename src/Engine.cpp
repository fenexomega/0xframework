#include "Engine.h"

#include "input/sysInput.h"
#include "graphics/Mesh.h"

#include "graphics/Window.h"
#include <utils/Timer.h>

using namespace ox;


Engine::Engine()
{
    InitSystems();
}

void Engine::InitSystems()
{
    Logger::CreateLogFile();
    LOG("Initializing Systems");
    SysGraphics::init();

    Window win;
    win.CreateWindow(800,600,"0xframework");
    SysGraphics::getGlInfo();

    //Automaticamente chmará esse função
    //na Saída.
    atexit(DisposeSystems);
}

void Engine::DisposeSystems()
{
    LOG("Disposing Systems");
    SysGraphics::dispose();
    LOG("Done.");
    Logger::CloseLogFile();
    exit(0);
}



void Engine::Run(Game *game)
{
    Window win;
	game->init();
    Timer time;
    double timeFrame,totalTime = 0;
    int framerate = 0;

    while(!win.UserWannaQuit())
    {
        timeFrame = time.getTime();
        totalTime += timeFrame;
        framerate++;

        if(totalTime >= 1.0)
        {
            PRINT(TOSTR(framerate) + " FPS");
            framerate = totalTime = 0;
        }

        sysInput::update();
        game->update(timeFrame);

        Buttons();

        game->draw(timeFrame);

        win.SwapBuffers();
    }
	game->dispose();

    delete game;

    win.Destroy();
}

void Engine::Buttons()
{
#ifndef RELEASE
    if(sysInput::isKeyDown(SDL_SCANCODE_F4))
        Mesh::PolygonMode = GL_TRIANGLES;
    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
        Mesh::PolygonMode = GL_LINES;
    if(sysInput::isKeyDown(SDL_SCANCODE_F6))
        Mesh::PolygonMode = GL_POINTS;
#endif
}

Engine::~Engine()
{

}

