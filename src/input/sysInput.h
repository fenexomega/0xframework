#ifndef SYSINPUT_H
#define SYSINPUT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

using namespace std;


namespace ox
{
#define NUM_KEYCODES 512
static const Uint8 * keys;
static const Uint8 * mouseKeys;

static vector<int> mouseDownKeys;
static vector<int> mouseUpKeys;
static vector<int> mouseCurrentKeys;


static vector<int> downKeys;
static vector<int> upKeys;
static vector<int> currentKeys;


class sysInput
{
public:
    static void update();

    static bool isKeyUp(int x);

    static bool isKeyDown(int x);

    static bool isKeyPressed(int x);

    static bool isMouseButtonUp(int x);

    static bool isMouseButtonDown(int x);

    static bool isMouseButtonPressed(int x);

    static bool isAnyKeyDown();

    static bool getKey(int key);

    static glm::vec2 getMousePos();

    static bool getMouseButton(int button);

//    static std::string getText();

};
}
#endif // INPUT_H
