#include "Engine.h"
#include "debug/MyGame.h"
#include "debug/Page38.h"
#include "debug/MeshTest.h"
#include "debug/GeometryShaderTest.h"

int main()
{
    Engine::InitSystems();
    Engine::Run(new MeshTest);
	return 0;
}
