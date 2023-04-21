#include "Pacman.h"

void Pacman::Update()
{
	CheckCollisionWithEnergy();

	if (moveDir == "Up")
		position.y--;
	else if (moveDir == "Right")
		position.x++;
	else if (moveDir == "Left")
		position.x--;
	else if (moveDir == "Down")
		position.y++;
}

void Pacman::CheckCollisionWithEnergy()
{
	if (position.x == energyPosition.x && position.y == energyPosition.y)
	{
		ghost->SetPacmanPowerPill(true);
	}
}

void Pacman::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}
Position Pacman::GetPosition()
{
	return position;
}

void Pacman::SetEnergyPosition(Position position)
{
	energyPosition = position;
}

void Pacman::SetMoveDir(string moveDir)
{
	this->moveDir = moveDir;
}
