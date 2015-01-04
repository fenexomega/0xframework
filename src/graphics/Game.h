#ifndef GAME
#define GAME

class Game
{
    virtual void Init() = 0;
    virtual void Pause() = 0;
    virtual void Dispose() = 0;
    virtual void Draw()   = 0;
    virtual void Update() = 0;
};

#endif // GAME

