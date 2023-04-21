#pragma once
#include "State.h"
#include "HuntedState.h"

class HunterState : public State
{
	HunterState() {}
public:
	void Execute(Ghost* ghost) override;
	static HunterState* getInstance();
};