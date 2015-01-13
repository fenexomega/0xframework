#include "Engine.h"

#include "input/sysInput.h"

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


    while(!win.UserWannaQuit())
    {
        SDL_Delay(1000/60);

        sysInput::update();
        game->update();


		game->draw();
        win.SwapBuffers();
    }
	game->dispose();

    delete game;

    win.Destroy();
}

Engine::~Engine()
{

}

