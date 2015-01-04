#include <iostream>
#include "Engine.h"
#include "project/MyGame.h"

int main()
{
    Engine::InitSystems();
    Engine::Run(new MyGame);
    Engine::DisposeSystems(0);
	return 0;
}
