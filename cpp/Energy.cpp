#include "Energy.h"

void Energy::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}
Position Energy::GetPosition()
{
	return position;
}