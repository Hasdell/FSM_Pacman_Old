#pragma once
#include "Position.h"
#include <string>

#define TIMER_SCARED 5
#define TIMER_GHOSTBOX 5
#define MAPXSIZE 60
#define MAPYSIZE 18

class State;
class Ghost
{
	Position position;
	Position startPosition;
	Position randomPosition;
	Position pacmanPosition;
	Position ghostBoxMinPosition;
	Position ghostBoxMaxPosition;
	State* currentState;
	double m_fTimer;
	bool m_bPacmanPowerPill;
	bool m_bBlocked;
public:
	Ghost();
	void Update();

	void Roam();
	void PathTo(std::string targetName);
	void PathAwayFrom(std::string targetName);
	void MoveBackandForth();

	bool CollisionWithGhostBox();
	bool CollisionWithPacman();
	
	void SetTimer(double time);
	double GetTimer();
	void SetPosition(int x, int y);
	Position GetPosition();

	bool IsHuntedState();
	bool IsEatenState();

	void SetRandomPosition();
	void SetPacmanPosition(Position position);
	void SetGhostBoxMinPosition(Position position);
	void SetGhostBoxMaxPosition(Position position);
	void SetPacmanPowerPill(bool powerPillState);
	bool GetPacmanPowerPill();
	bool IsGetCloseEnough();


	void ChangeState(State* pNewState);

};