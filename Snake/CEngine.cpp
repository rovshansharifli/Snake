#include "CEngine.h"
#include "Params.h"
#include "CPlayGround.h"

CEngine::CEngine()
{
	//set textures
	m_texture.loadFromFile("images/tiles.png");
	m_snakeSprite.setTexture(m_texture);
	m_fruitSprite.setTexture(m_texture);

	m_snakeSprite.setTextureRect(sf::IntRect(0, 0, 18, 18));
	m_fruitSprite.setTextureRect(sf::IntRect(18, 0, 18, 18));
}

CEngine::~CEngine()
{
}

void CEngine::start()
{
	sf::RenderWindow window(sf::VideoMode(snakePGSize::WIDTH * 18, snakePGSize::HEIGHT * 18), "Snake game");
	
	sf::Clock clock;

	CPlayGround myPG;

	//initialize snake and fruit positions
	myPG.putSnakeOnPG();
	myPG.putFruitOnPG();

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		checkEvent(window);

		if (timer > delay) {
			//slide the piece here
			myPG.slideSnake();
			myPG.putSnakeOnPG();

			timer = 0;
		}

		window.clear(sf::Color::White);

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

