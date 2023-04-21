#pragma once
#include "Ghost.h"
#include "Pacman.h"
#include "Energy.h"

class GameMap
{
	Ghost* ghost;
	Pacman* pacman;
	Energy* energy;
	int** m_map;
	bool** m_visitInfo;
	int m_width;
	int m_height;
public:
	GameMap(int w, int h, Ghost* ghost, Pacman* pacman, Energy* energy) : m_width(w), m_height(h), ghost(ghost), pacman(pacman), energy(energy)
	{
		m_map = new int* [h];
		m_visitInfo = new bool* [h];
		for (int i = 0; i < h; i++)
		{
			m_map[i] = new int[w];
			m_visitInfo[i] = new bool[w];
		}
		InitMap();
	}
	~GameMap()
	{
		for (int i = 0; i < m_height; i++)
		{
			delete m_map[i];
			delete m_visitInfo[i];
		}
		delete m_map;
		delete m_visitInfo;
	}
	void InitMap(); // ¸Ê ÃÊ±âÈ­

	// getters
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getMapVal(int x, int y) { return m_map[y][x]; }
	bool getVisitInfo(int x, int y) { return m_visitInfo[y][x]; }

	// setters
	void setMapVal(int x, int y, int val) { m_map[y][x] = val; }
	void setVisitInfo(int x, int y, bool val) { m_visitInfo[y][x] = val; }

	void draw();
	void gotoxy(int x, int y);
};