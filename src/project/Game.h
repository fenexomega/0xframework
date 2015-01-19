#ifndef GAME_H
#define GAME_H

namespace ox
{
class Game
{
private:
protected:

public:

    virtual void init() = 0;

    virtual void update(double delta) = 0;

	virtual void pause() = 0;

    virtual void draw(double delta) = 0;

	virtual void dispose() = 0;

};
}
#endif
