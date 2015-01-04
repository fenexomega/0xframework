#include "sysInput.h"



#define NUM_KEYCODES 256

const Uint8 * sysInput::keys;
const Uint8 * sysInput::mouseKeys;

 vector<int> sysInput::mouseDownKeys;
 vector<int> sysInput::mouseUpKeys;
 vector<int> sysInput::mouseCurrentKeys;


 vector<int> sysInput::downKeys;
 vector<int> sysInput::upKeys;
 vector<int> sysInput::currentKeys;

void sysInput::update()
{
    SDL_PumpEvents();
    keys = SDL_GetKeyboardState(NULL);
    int i;
    //TODO Mouse Unput!


    mouseUpKeys.clear();
    for(i = 0; i < 4; i++)
        if(!getMouseButton(i) && (find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()) )
            mouseUpKeys.push_back(i);

    mouseDownKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i) && !(find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()))
            mouseDownKeys.push_back(i);

    mouseCurrentKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i))
            mouseCurrentKeys.push_back(i);



    upKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(!getKey(i) && (find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()) )
            upKeys.push_back(i);

    downKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i) && !(find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()))
            downKeys.push_back(i);

    currentKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i))
            currentKeys.push_back(i);

}

bool sysInput::isAnyKeyDown()
{
    for(int i = 0; i < 300; i++)
        if(isKeyPressed(i) || isKeyDown(i))
            return true;
    return false;
}
