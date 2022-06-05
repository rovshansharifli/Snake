#pragma once
#include "Cell.h"
#include <vector>

class CSnake
{
public:
	CSnake();
	~CSnake();

	std::vector<Cell>* getSnake();

	void setDirection(int t_direction);
	int getDirection();

	void slideSnake();

private:
	std::vector<Cell> mySnakeVector;
	// direction - 0 up; 1 right; 2 down; 3 left
	int m_direction = 1;
};

