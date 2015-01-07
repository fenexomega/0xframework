#include <iostream>
#include "Engine.h"
#include "project/MyGame.h"
#include "project/Page38.h"

int main()
{
    Engine::InitSystems();
    Engine::Run(new Page38);
    Engine::DisposeSystems(0);
	return 0;
}
