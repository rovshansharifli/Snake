#include "CSnake.h"

CSnake::CSnake()
{
	Cell head;
	head.x = 9;
	head.y = 9;

	mySnakeVector.push_back(head);
}

CSnake::~CSnake()
{
}

std::vector<Cell>* CSnake::getSnake()
{
	return &mySnakeVector;
}


