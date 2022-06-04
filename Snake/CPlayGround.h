#pragma once
#include "Params.h"
#include "CSnake.h"
#include <SFML/Graphics.hpp>

class CPlayGround
{
public:
	CPlayGround();
	~CPlayGround();

	void putSnakeOnPG();

	void putFruitOnPG();

	void putAllOnScreen(sf::RenderWindow& t_window, sf::Sprite& t_snakeSprite, sf::Sprite& t_fruitSprite);

private:
	// 0 is empty space
	// 1 is for snake body
	// 2 is for friut
	int m_playGround[snakePGSize::WIDTH][snakePGSize::HEIGHT] = { 0 };
	CSnake m_Snake;

};

