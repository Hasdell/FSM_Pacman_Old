#include "HuntedState.h"

void HuntedState::Execute(Ghost* ghost)
{
	if (ghost->GetTimer() <= 0)
	{
		ghost->ChangeState(HunterState::getInstance());
	}
	if (ghost->CollisionWithPacman())
	{
		ghost->ChangeState(EatenState::getInstance());
	}
	
	ghost->PathAwayFrom("Pacman");
}
HuntedState* HuntedState::getInstance()
{
	static HuntedState* instance;
	if (instance == nullptr)
		instance = new HuntedState();
	return instance;
}