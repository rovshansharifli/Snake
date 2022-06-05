#include "CSnake.h"

CSnake::CSnake()
{
	Cell head;
	head.x = 9;
	head.y = 9;

	mySnakeVector.push_back(head);

	head.x = 8;
	head.y = 9;

	mySnakeVector.push_back(head);

	head.x = 7;
	head.y = 9;

	mySnakeVector.push_back(head);

	head.x = 6;
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

void CSnake::setDirection(int t_direction)
{
	switch (t_direction)
	{
	case 0:
		if (m_direction == 2) {
			break;
		}
		else {
			m_direction = t_direction;
		}
		break;
	case 1:
		if (m_direction == 3) {
			break;
		}
		else {
			m_direction = t_direction;
		}
		break;
	case 2:
		if (m_direction == 0) {
			break;
		}
		else {
			m_direction = t_direction;
		}
		break;
	case 3:
		if (m_direction == 1) {
			break;
		}
		else {
			m_direction = t_direction;
		}
		break;
	}

	
	
}

int CSnake::getDirection()
{
	return m_direction;
}

void CSnake::slideSnake()
{
	Cell newSnakeHead;

	newSnakeHead.x = mySnakeVector.begin()->x;
	newSnakeHead.y = mySnakeVector.begin()->y;

	// move snake head
	// direction - 0 up; 1 right; 2 down; 3 left
	switch (m_direction)
	{
	case 0:
		newSnakeHead.y = newSnakeHead.y - 1;
		break;
	case 1:
		newSnakeHead.x = newSnakeHead.x + 1;
		break;
	case 2:
		newSnakeHead.y = newSnakeHead.y + 1;
		break;
	case 3:
		newSnakeHead.x = newSnakeHead.x - 1;
		break;
	}

	//move snake body
	Cell next = newSnakeHead;

	for (auto it = mySnakeVector.begin(); it != mySnakeVector.end(); it++)
	{
		int oldX = it->x;
		int oldY = it->y;

		it->x = next.x;
		it->y = next.y;

		next.x = oldX;
		next.y = oldY;

	}
}


