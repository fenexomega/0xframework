#include "Timer.h"


double Timer::getTime()
{
    oldTime = nowTime;
    nowTime = SDL_GetTicks();

    return double(nowTime - oldTime)/1000.f;
}

Timer::Timer()
{
    nowTime = 0;
}

Timer::~Timer()
{

}

