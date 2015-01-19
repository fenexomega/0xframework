#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>


class Timer
{
private:
    Uint32 nowTime;
    Uint32 oldTime;
public:
    double getTime();
    Timer();
    ~Timer();
};

#endif // TIMER_H
