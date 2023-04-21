#pragma once
#include "Position.h"

class GhostBox
{
	Position minPosition;
	Position maxPosition;
public:
	void SetMinPosition(int x, int y);
	Position GetMinPosition();
	void SetMaxPosition(int x, int y);
	Position GetMaxPosition();
};