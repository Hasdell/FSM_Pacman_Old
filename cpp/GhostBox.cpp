#include "GhostBox.h"

void GhostBox::SetMinPosition(int x, int y)
{
	this->minPosition.x = x;
	this->minPosition.y = y;
}
Position GhostBox::GetMinPosition()
{
	return minPosition;
}
void GhostBox::SetMaxPosition(int x, int y)
{
	this->maxPosition.x = x;
	this->maxPosition.y = y;
}
Position GhostBox::GetMaxPosition()
{
	return maxPosition;
}