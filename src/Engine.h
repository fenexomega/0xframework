#ifndef ENGINE_H
#define ENGINE_H

#include "GlobalDef.h"
#include "graphics/SysGraphics.h"
#include "project/Game.h"

class Engine
{

private:
    Engine();
    ~Engine();
public:
    static void DisposeSystems(int signal);
    static void InitSystems();
    static void Run(Game *game);
    static void CreateWindow(int width,int height,std::string title);

};

#endif // ENGINE_H
