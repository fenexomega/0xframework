#ifndef GAME
#define GAME


class Game
{
private:
protected:

public:

        virtual void update() = 0;

	virtual void draw() = 0;

	virtual void pause() = 0;

	virtual void init() = 0;

	virtual void dispose() = 0;


};

#endif
