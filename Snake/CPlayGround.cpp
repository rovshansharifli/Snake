#include "CPlayGround.h"
#include "Cell.h"

#include <iostream>

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
	int fruitX = rand() % (snakePGSize::WIDTH - 1);
	int fruitY = rand() % (snakePGSize::HEIGHT - 1);

	while (m_playGround[fruitX][fruitY] != 0) {
		fruitX = rand() % (snakePGSize::WIDTH - 1);
		fruitY = rand() % (snakePGSize::HEIGHT - 1);
	}

	std::cout << fruitX << std::endl;
	std::cout << fruitY << std::endl;

	m_playGround[fruitX][fruitY] = 2;
	fruitPos.x = fruitX;
	fruitPos.y = fruitY;

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



