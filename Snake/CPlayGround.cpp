#include "CPlayGround.h"
#include "Cell.h"

CPlayGround::CPlayGround()
{
	
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



