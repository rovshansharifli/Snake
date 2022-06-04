#pragma once
#include "Cell.h"
#include <vector>

class CSnake
{
public:
	CSnake();
	~CSnake();

	std::vector<Cell>* getSnake();

private:

	std::vector<Cell> mySnakeVector;
};

