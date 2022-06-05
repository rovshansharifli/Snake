#include "CSnake.h"
#include "Params.h"

CSnake::CSnake()
{
	Cell head;
	head.x = snakePGSize::WIDTH / 2;
	head.y = snakePGSize::HEIGHT / 2;

	mySnakeVector.push_back(head);

	head.x = head.x - 1;
	head.y = head.y;

	mySnakeVector.push_back(head);

	head.x = head.x - 1;
	head.y = head.y;

	mySnakeVector.push_back(head);

	head.x = head.x - 1;
	head.y = head.y;

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

void CSnake::slideSnake(Cell t_newHead)
{
	//move snake body
	Cell next = t_newHead;

	//if tried to go back
	if (!((next.x == (mySnakeVector.begin()+1)->x) && (next.y == (mySnakeVector.begin()+1)->y))) {
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
	else {
		switch (m_direction)
		{
		case 0:
			m_direction = 2;
			break;
		case 1:
			m_direction = 3;
			break;
		case 2:
			m_direction = 0;
			break;
		case 3:
			m_direction = 1;
			break;
		}
	}
}

Cell CSnake::getNewSnakeHead()
{
	Cell newSnakeHead;

	newSnakeHead.x = mySnakeVector.begin()->x;
	newSnakeHead.y = mySnakeVector.begin()->y;

	// move snake head
	// direction - 0 up; 1 right; 2 down; 3 left
	switch (m_direction)
	{
	case 0:
		if ((newSnakeHead.y - 1) < 0)
		{
			newSnakeHead.y = snakePGSize::HEIGHT - 1;
		}
		else {
			newSnakeHead.y = newSnakeHead.y - 1;
		}

		break;
	case 1:
		if ((newSnakeHead.x + 1) > snakePGSize::WIDTH - 1)
		{
			newSnakeHead.x = 0;
		}
		else {
			newSnakeHead.x = newSnakeHead.x + 1;
		}
		break;
	case 2:
		if ((newSnakeHead.y + 1) > snakePGSize::HEIGHT - 1)
		{
			newSnakeHead.y = 0;
		}
		else {
			newSnakeHead.y = newSnakeHead.y + 1;
		}
		break;
	case 3:
		if ((newSnakeHead.x - 1) < 0)
		{
			newSnakeHead.x = snakePGSize::WIDTH - 1;
		}
		else {
			newSnakeHead.x = newSnakeHead.x - 1;
		}
		break;
	}
	return newSnakeHead;
}

void CSnake::growSnake(Cell t_newBody)
{
	mySnakeVector.push_back(t_newBody);
}


