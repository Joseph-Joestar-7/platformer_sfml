#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 900),"Mario I guess");
	sf::Clock deltaClock;

	Begin(window);
	while (window.isOpen())
	{
		float deltaTime = deltaClock.restart().asSeconds();

		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();	
		}
		Update(deltaTime);

		window.clear();

		Render(window);

		window.display();
	}
}


