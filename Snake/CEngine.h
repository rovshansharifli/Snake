#pragma once
#include <SFML/Graphics.hpp>

class CEngine
{
public:
	CEngine();
	~CEngine();

	void start();

private:
	void checkEvent(sf::RenderWindow& t_window);

	//texture things
	sf::Texture m_texture;
	sf::Sprite m_snakeSprite;
	sf::Sprite m_fruitSprite;

	//to slide the snake
	float timer = 0;
	float delay = 0.3;

};

