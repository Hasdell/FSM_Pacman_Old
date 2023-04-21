#include "Ghost.h"
#include "InBoxState.h"
#include <random>

Ghost::Ghost()
{
	currentState = InBoxState::getInstance();
	SetTimer(TIMER_GHOSTBOX);
}
void Ghost::Update()
{
	currentState->Execute(this);
}

//배회
void Ghost::Roam()
{
	if (position.x == randomPosition.x && position.y == randomPosition.y)
		SetRandomPosition();

	if (abs(randomPosition.x - position.x) > abs(randomPosition.y - position.y))
	{
		if (position.x > randomPosition.x)
		{
			if ((position.x - 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x - 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
			{
				position.y++;
				return;
			}
			position.x--;
		}
		else if (position.x < randomPosition.x)
		{
			if ((position.x + 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x + 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
			{
				position.y++;
				return;
			}
			position.x++;
		}
	}
	else
	{
		if (position.y > randomPosition.y)
		{
			if ((position.y - 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y - 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
			{
				position.x++;
				return;
			}
			position.y--;
		}
		else if (position.y < randomPosition.y)
		{
			if ((position.y + 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y + 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
			{
				position.x++;
				return;
			}
			position.y++;
		}
	}
}
//추적
void Ghost::PathTo(std::string targetName)
{
	if (targetName == "Pacman")
	{
		if (abs(pacmanPosition.x - position.x) > abs(pacmanPosition.y - position.y))
		{
			if (position.x > pacmanPosition.x)
			{
				if ((position.x - 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x - 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				position.x--;
			}
			else if (position.x < pacmanPosition.x)
			{
				if ((position.x + 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x + 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				position.x++;
			}
		}
		else
		{
			if (position.y > pacmanPosition.y)
			{
				if ((position.y - 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y - 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				position.y--;
			}
			else if (position.y < pacmanPosition.y)
			{
				if ((position.y + 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y + 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				position.y++;
			}
		}
	}
	else if (targetName == "GhostBox")
	{
		if (abs(pacmanPosition.x - position.x) > abs(pacmanPosition.y - position.y))
		{
			if (position.x > startPosition.x)
			{
				if ((position.x - 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x - 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				position.x--;
			}
			else if (position.x < startPosition.x)
			{
				if ((position.x + 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x + 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				position.x++;
			}
		}
		else
		{
			if (position.y > startPosition.y)
			{
				if ((position.y - 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y - 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				position.y--;
			}
			else if (position.y < startPosition.y)
			{
				if ((position.y + 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y + 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				position.y++;
			}
		}
	}
}
//도망
void Ghost::PathAwayFrom(std::string targetName)
{
	if (targetName == "Pacman")
	{
		if (abs(pacmanPosition.x - position.x) > abs(pacmanPosition.y - position.y))
		{
			if (position.x > pacmanPosition.x)
			{
				if ((position.x + 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x + 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				if ((position.x + 1) == MAPXSIZE - 1)
				{
					return;
				}
				position.x++;
			}
			else if (position.x < pacmanPosition.x)
			{
				if ((position.x - 1) == ghostBoxMinPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y || (position.x - 1) == ghostBoxMaxPosition.x && position.y >= ghostBoxMinPosition.y && position.y <= ghostBoxMaxPosition.y)
				{
					position.y++;
					return;
				}
				if ((position.x - 1) == 0)
				{
					return;
				}
				position.x--;
			}
		}
		else
		{
			if (position.y > pacmanPosition.y)
			{
				if ((position.y + 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y + 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				if ((position.y + 1) == MAPYSIZE - 1)
				{
					return;
				}
				position.y++;
			}
			else if (position.y < pacmanPosition.y)
			{
				if ((position.y - 1) == ghostBoxMaxPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x || (position.y - 1) == ghostBoxMinPosition.y && position.x == ghostBoxMinPosition.x || position.x == ghostBoxMaxPosition.x)
				{
					position.x++;
					return;
				}
				if ((position.y - 1) == 0)
				{
					return;
				}
				position.y--;
			}
		}
	}
}
//앞뒤로 이동
void Ghost::MoveBackandForth()
{
	if (!m_bBlocked)
	{
		if ((position.x + 1) < ghostBoxMaxPosition.x)
			position.x++;
		else
		{
			position.x--;
			m_bBlocked = !m_bBlocked;
		}
	}
	else
	{
		if ((position.x - 1) > ghostBoxMinPosition.x)
			position.x--;
		else
		{
			position.x++;
			m_bBlocked = !m_bBlocked;
		}
	}
}

bool Ghost::CollisionWithGhostBox()
{
	if (position.x > ghostBoxMinPosition.x && position.y > ghostBoxMinPosition.y && position.x < ghostBoxMaxPosition.x && position.y < ghostBoxMaxPosition.y)
		return true;
	return false;
}
bool Ghost::CollisionWithPacman()
{
	if (position.x == pacmanPosition.x && position.y == pacmanPosition.y)
		return true;
	return false;
}

void Ghost::SetTimer(double time)
{
	m_fTimer = time;
}
double Ghost::GetTimer()
{
	return m_fTimer;
}
void Ghost::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
	startPosition = this->position;
}
Position Ghost::GetPosition()
{
	return position;
}

bool Ghost::IsHuntedState()
{
	if (currentState == HuntedState::getInstance())
		return true;
	return false;
}
bool Ghost::IsEatenState()
{
	if (currentState == EatenState::getInstance())
		return true;
	return false;
}

void Ghost::SetRandomPosition()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> disx(1, 59);
	std::uniform_int_distribution<int> disy(1, 16);

	randomPosition.x = disx(gen);
	randomPosition.y = disy(gen);

	if (randomPosition.x == ghostBoxMinPosition.x || randomPosition.x == ghostBoxMaxPosition.x || randomPosition.y == ghostBoxMinPosition.y || randomPosition.y == ghostBoxMaxPosition.y)
		SetRandomPosition();
}
void Ghost::SetPacmanPosition(Position position)
{
	pacmanPosition = position;
}
void Ghost::SetGhostBoxMinPosition(Position position)
{
	ghostBoxMinPosition = position;
}
void Ghost::SetGhostBoxMaxPosition(Position position)
{
	ghostBoxMaxPosition = position;
}
void Ghost::SetPacmanPowerPill(bool powerPillState)
{
	m_bPacmanPowerPill = powerPillState;
}
bool Ghost::GetPacmanPowerPill()
{
	return m_bPacmanPowerPill;
}
bool Ghost::IsGetCloseEnough()
{
	if (abs((pacmanPosition.x + pacmanPosition.y) - (position.x + position.y)) < 10)
		return true;
	return false;
}

void Ghost::ChangeState(State* pNewState)
{
	
	currentState = pNewState;
}