#include <iostream>
#include "Engine.h"
#include "project/MyGame.h"
#include "project/Page38.h"
#include "project/MeshTest.h"

int main()
{
    Engine::InitSystems();
    Engine::Run(new MeshTest);
    Engine::DisposeSystems(EXIT_SUCCESS);
	return 0;
}
