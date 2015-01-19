#ifndef GEOMETRYSHADERTEST_H
#define GEOMETRYSHADERTEST_H

#include <vector>


#include "project/Game.h"
#include "graphics/Program.h"
#include "graphics/Mesh.h"
#include "graphics/Camera.h"

using namespace ox;


class GeometryShaderTest : public Game
{
private:
    Program *program;
    std::vector<Mesh *> meshes;
    Camera *cam;
public:
    GeometryShaderTest();
    ~GeometryShaderTest();

    // Game interface
    void init();
    void update(double delta);
    void pause();
    void draw();
    void dispose();
};

#endif // GEOMETRYSHADERTEST_H
