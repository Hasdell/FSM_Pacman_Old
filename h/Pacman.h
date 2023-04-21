#pragma once
#include "Position.h"
#include "Ghost.h"
#include <string>
using namespace std;

class Pacman
{
	Ghost* ghost;
	Position position;
	Position energyPosition;
	string moveDir;
	bool m_powerPill;
public:
	Pacman(Ghost* ghost) : m_powerPill(false), ghost(ghost){}
	void Update();

	void CheckCollisionWithEnergy();

	void SetPosition(int x, int y);
	Position GetPosition();

	void SetEnergyPosition(Position position);

	void SetMoveDir(string moveDir);
};