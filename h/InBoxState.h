#pragma once
#include "State.h"
#include "HunterState.h"

class InBoxState : public State
{
	InBoxState() {}
public:
	void Execute(Ghost* ghost) override;
	static InBoxState* getInstance();
};