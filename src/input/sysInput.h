#ifndef SYSINPUT_H
#define SYSINPUT_H

#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>

#include "math/Vector.h"

using namespace std;

#define NUM_KEYCODES 256



class sysInput
{
private:
    static const Uint8 * keys;
    static const Uint8 * mouseKeys;

    static vector<int> mouseDownKeys;
    static vector<int> mouseUpKeys;
    static vector<int> mouseCurrentKeys;


    static vector<int> downKeys;
    static vector<int> upKeys;
    static vector<int> currentKeys;
public:
    static void update();

    static bool isKeyUp(int x)
    {
        return find(upKeys.begin(),upKeys.end(),x) != upKeys.end();
    }

    static bool isKeyDown(int x)
    {
        return find(downKeys.begin(),downKeys.end(),x) != downKeys.end();
    }

    static bool isKeyPressed(int x)
    {
        return find(currentKeys.begin(),currentKeys.end(),x) != currentKeys.end();
    }

    static bool isMouseButtonUp(int x)
    {
        return find(mouseUpKeys.begin(),mouseUpKeys.end(),x) != mouseUpKeys.end();
    }

    static bool isMouseButtonDown(int x)
    {
        return find(mouseDownKeys.begin(),mouseDownKeys.end(),x) != mouseDownKeys.end();
    }

    static bool isMouseButtonPressed(int x)
    {
        return find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),x) != mouseCurrentKeys.end();
    }


    static bool isAnyKeyDown();

    static bool getKey(int key)
    {
        return keys[key] == 1;
    }

    static Vector2D getMousePos()
    {
        int x,y;
        SDL_GetMouseState(&x,&y);
        Vector2D aux(x,y);
        return aux;

    }

    static bool getMouseButton(int button)
    {
        return SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(button);
    }

};

#endif // INPUT_H
