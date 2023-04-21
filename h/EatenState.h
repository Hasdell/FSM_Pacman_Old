#pragma once
#include "State.h"
#include "InBoxState.h"

class EatenState : public State
{
	EatenState() {}
public:
	void Execute(Ghost* ghost) override;
	static EatenState* getInstance();
};