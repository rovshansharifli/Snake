#include "CEngine.h"
#include "Params.h"

CEngine::CEngine()
{
	m_texture.loadFromFile("images/tiles.png");

}

CEngine::~CEngine()
{
}

void CEngine::start()
{
	sf::RenderWindow window(sf::VideoMode(snakeWinSize::WIDTH, snakeWinSize::HEIGHT), "Snake game");
	setTexture();
	
	CPlayGround myPG;

	while (window.isOpen()) {
		checkEvent(window);

		window.clear(sf::Color::White);
		myPG.putSnakeOnPG();

		myPG.putAllOnScreen(window, m_snakeSprite, m_fruitSprite);

		window.display();
	}
}

void CEngine::checkEvent(sf::RenderWindow& t_window)
{
	sf::Event myEvent;

	while (t_window.pollEvent(myEvent)) {
		if (myEvent.type == sf::Event::Closed) {
			t_window.close();
		}
	}
}

void CEngine::setTexture()
{
	m_snakeSprite.setTexture(m_texture);
	m_fruitSprite.setTexture(m_texture);

	m_snakeSprite.setTextureRect(sf::IntRect(0, 0, 18, 18));
	m_fruitSprite.setTextureRect(sf::IntRect(18, 0, 18, 18));
}
