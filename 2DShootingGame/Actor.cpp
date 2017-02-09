#include "Actor.h"

void Actor::Draw()
{
	DrawGraph(x, y, handle, false);
}

void Actor::Move()
{
	x++;
	y++;

	//if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = 0;
	//if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = 0;
}

State Actor::All()
{
	Move();
	Draw();

	return this->state;
}
