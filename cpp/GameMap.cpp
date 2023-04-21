#include "GameMap.h"

void GameMap::InitMap()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_map[y][x] = 1000;
			if (y == 0 || y == m_height - 1 || x == 0 || x == m_width - 1)
			{
				m_map[y][x] = 56;
			}
			if (x >= 40 && x <= 45 && y >= 5 && y <= 10)
			{
				m_map[y][x] = 56;
				if (y > 5 && y < 10 && x >= 41 && x <= 44)
				{
					m_map[y][x] = 1000;
				}
				if (y == 5 || y == 10 && x >= 41 && x <= 44)
				{
					m_map[y][x] = 1000;
				}
			}
				
			m_visitInfo[y][x] = false;
		}
	}
}
#include <Windows.h>
void GameMap::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#include <iostream>
using namespace std;
void GameMap::draw()
{
	gotoxy(0, 0);
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (pacman->GetPosition().x == x && pacman->GetPosition().y == y)
			{
				cout << "P";
				continue;
			}
			if (ghost->GetPosition().x == x && ghost->GetPosition().y == y)
			{
				if (ghost->IsHuntedState())
				{
					cout << "X";
					continue;
				}
				if (ghost->IsEatenState())
				{
					cout << "O";
					continue;
				}
				cout << "G";
				continue;
			}
			if (energy->GetPosition().x == x && energy->GetPosition().y == y)
			{
				cout << "*";
				continue;
			}
			if (m_map[y][x] != 56)
			{
				cout << " ";
				continue;
			}
			cout << (char)m_map[y][x];
		}
		cout << endl;
	}
}