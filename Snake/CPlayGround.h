#pragma once
#include "Params.h"
#include "CSnake.h"
#include <SFML/Graphics.hpp>

class CPlayGround
{
public:
	CPlayGround();
	~CPlayGround();

	//initializing the snake and fruit
	void putSnakeOnPG();
	void putFruitOnPG();

	//sliding the snake
	void slideSnake();

	//putting all everything on the screen
	void putAllOnScreen(sf::RenderWindow& t_window, sf::Sprite& t_snakeSprite, sf::Sprite& t_fruitSprite);

private:
	// 0 is empty space
	// 1 is for snake body
	// 2 is for friut
	int m_playGround[snakePGSize::WIDTH][snakePGSize::HEIGHT] = { 0 };
	CSnake m_Snake;

	Cell fruitPos;

};

