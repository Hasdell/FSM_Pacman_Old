#include "GameMap.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Energy.h"
#include "GhostBox.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;

bool gameOver = false;
void PlayerMove(Pacman* pacman);
void PacmanUpdate(Pacman* pacman, Ghost* ghost);
void GhostUpdate(Ghost* ghost);
bool CheckGameOver();
int main()
{
	Ghost ghost;
	Pacman pacman(&ghost);
	Energy energy;
	GhostBox ghostBox;

	pacman.SetPosition(10, 10);
	ghost.SetPosition(42, 8);
	energy.SetPosition(20, 10);
	ghostBox.SetMinPosition(40, 5);
	ghostBox.SetMaxPosition(45, 10);

	ghost.SetPacmanPosition(pacman.GetPosition());
	ghost.SetGhostBoxMinPosition(ghostBox.GetMinPosition());
	ghost.SetGhostBoxMaxPosition(ghostBox.GetMaxPosition());
	pacman.SetEnergyPosition(energy.GetPosition());
	pacman.SetMoveDir("Right");

	GameMap gameMap(MAPXSIZE, MAPYSIZE, &ghost, &pacman, &energy);
	thread t1 = thread(PlayerMove, &pacman);
	thread t2 = thread(PacmanUpdate, &pacman, &ghost);
	thread t3 = thread(GhostUpdate, &ghost);

	while (1)
	{
		gameMap.draw();

		if (!ghost.IsHuntedState() && !ghost.IsEatenState())
		{
			if (ghost.CollisionWithPacman())
			{
				gameOver = true;
				break;
			}
		}
	}
	
	cout << "Game Over" << endl;

	return 0;
}
void PlayerMove(Pacman* pacman)
{
	while (1)
	{
		if (CheckGameOver())
			return;

		if (_kbhit())
		{
			int key = _getch();

			switch (key)
			{
			case 72:
				pacman->SetMoveDir("Up");
				break;
			case 77:
				pacman->SetMoveDir("Right");
				break;
			case 80:
				pacman->SetMoveDir("Down");
				break;
			case 75:
				pacman->SetMoveDir("Left");
				break;
			}
		}
	}
}
void PacmanUpdate(Pacman* pacman, Ghost* ghost)
{
	while (1)
	{
		if (CheckGameOver())
			return;

		pacman->Update();
		ghost->SetPacmanPosition(pacman->GetPosition());
		
		Sleep(130);
	}
}
void GhostUpdate(Ghost* ghost)
{
	while (1)
	{
		if (CheckGameOver())
			return;

		ghost->Update();

		Sleep(130);
		ghost->SetTimer(ghost->GetTimer() - 0.13);
	}
}
bool CheckGameOver()
{
	return gameOver;
}