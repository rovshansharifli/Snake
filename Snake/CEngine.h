#pragma once
#include <SFML/Graphics.hpp>
#include "Params.h"
#include "CPlayGround.h"

class CEngine
{
public:
	CEngine();
	~CEngine();

	void start();

private:
	void checkEvent(sf::RenderWindow& t_window);

	void setTexture();

	sf::Texture m_texture;
	sf::Sprite m_snakeSprite;
	sf::Sprite m_fruitSprite;
};

