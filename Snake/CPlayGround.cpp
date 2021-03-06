#include "CPlayGround.h"
#include "Cell.h"

CPlayGround::CPlayGround()
{
	srand(time(0));

}

CPlayGround::~CPlayGround()
{

}

void CPlayGround::putSnakeOnPG()
{
	std::vector<Cell>* snakeCells = m_Snake.getSnake();

	for (auto it = snakeCells->begin(); it != snakeCells->end(); it++) 
	{
		m_playGround[it->x][it->y] = 1;
	}
}

void CPlayGround::putFruitOnPG()
{
	int fruitX = rand() % snakePGSize::WIDTH;
	int fruitY = rand() % snakePGSize::HEIGHT;

	while (m_playGround[fruitX][fruitY] != 0) {
		fruitX = rand() % snakePGSize::WIDTH;
		fruitY = rand() % snakePGSize::HEIGHT;
	}

	m_playGround[fruitX][fruitY] = 2;

	fruitPos.x = fruitX;
	fruitPos.y = fruitY;
}

bool CPlayGround::slideSnake()
{
	Cell newHead = m_Snake.getNewSnakeHead();

	if (m_playGround[newHead.x][newHead.y] == 1) {
		return false;
	}
	else if (m_playGround[newHead.x][newHead.y] == 2) {
		m_Snake.growSnake(newHead);
		putFruitOnPG();
	}

	std::vector<Cell>* snakeCells = m_Snake.getSnake();
	for (auto it = snakeCells->begin(); it != snakeCells->end(); it++)
	{
		m_playGround[it->x][it->y] = 0;
	}

	m_Snake.slideSnake(newHead);

	return true;
}

void CPlayGround::setSnakeDirection(int t_direction)
{
	m_Snake.setDirection(t_direction);
}

void CPlayGround::generateFruit()
{

}

void CPlayGround::putAllOnScreen(sf::RenderWindow& t_window, sf::Sprite& t_snakeSprite, sf::Sprite& t_fruitSprite)
{
	for (int i = 0; i < snakePGSize::WIDTH; i++) {
		for (int j = 0; j < snakePGSize::HEIGHT; j++) {
			switch (m_playGround[i][j])
			{
			case 1:
				t_snakeSprite.setPosition(i * 18, j * 18);
				t_window.draw(t_snakeSprite);
				break;
			case 2:
				t_fruitSprite.setPosition(i * 18, j * 18);
				t_window.draw(t_fruitSprite);
				break;
			}
		}
	}
}

int CPlayGround::getSnakeLength()
{
	return m_Snake.getSnake()->size();
}



