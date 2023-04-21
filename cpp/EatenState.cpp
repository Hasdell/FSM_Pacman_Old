#include "EatenState.h"

void EatenState::Execute(Ghost* ghost)
{
	if (ghost->CollisionWithGhostBox())
	{
		ghost->SetTimer(TIMER_GHOSTBOX);
		ghost->ChangeState(InBoxState::getInstance());
	}

	ghost->PathTo("GhostBox");
}
EatenState* EatenState::getInstance()
{
	static EatenState* instance;
	if (instance == nullptr)
		instance = new EatenState();
	return instance;
}