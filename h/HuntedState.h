#pragma once
#include "State.h"
#include "HunterState.h"
#include "EatenState.h"

class HuntedState : public State
{
	HuntedState() {}
public:
	void Execute(Ghost* ghost) override;
	static HuntedState* getInstance();
};