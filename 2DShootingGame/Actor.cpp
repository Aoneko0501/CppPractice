#include "Actor.h"

float Actor::getX()
{
	return this->x;
}

float Actor::getY()
{
	return this->y;
}

State Actor::getState()
{
	return this->state;
}

void Actor::setState(State s)
{
	this->state = s;
}

void Actor::Draw()
{
	if(this->state == State::ALIVE)DrawGraph(x, y, handle, false);
}

void Actor::Move()
{
	x++;
	//y++;

	//if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = 0;
	//if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = 0;
}

void Actor::Shot()
{

}

State Actor::All()
{
	Move();
	Draw();
	Shot();
	return this->state;
}
