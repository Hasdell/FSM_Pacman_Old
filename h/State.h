#pragma once
#include "Ghost.h"

class State
{
public:
	virtual ~State() {}
	virtual void Execute(Ghost* ghost) = 0;
};