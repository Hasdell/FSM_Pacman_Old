#include "InBoxState.h"

void InBoxState::Execute(Ghost* ghost)
{
	if (ghost->GetTimer() <= 0)
	{
		ghost->SetRandomPosition();
		ghost->ChangeState(HunterState::getInstance());
	}

	ghost->MoveBackandForth();
}
InBoxState* InBoxState::getInstance()
{
	static InBoxState* instance;
	if (instance == nullptr)
		instance = new InBoxState();
	return instance;
}