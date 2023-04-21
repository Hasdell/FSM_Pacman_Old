#include "HunterState.h"

void HunterState::Execute(Ghost* ghost)
{
	if (ghost->GetPacmanPowerPill())
	{
		ghost->SetPacmanPowerPill(false);
		ghost->SetTimer(TIMER_SCARED);
		ghost->ChangeState(HuntedState::getInstance());
	}

	if (ghost->IsGetCloseEnough())
	{
		ghost->PathTo("Pacman");
		return;
	}
	ghost->Roam();
}
HunterState* HunterState::getInstance()
{
	static HunterState* instance;
	if (instance == nullptr)
		instance = new HunterState();
	return instance;
}