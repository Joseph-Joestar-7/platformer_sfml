#include "Game.h"

sf::Texture texture;


void Begin(const sf::RenderWindow& window)
{
	if (!texture.loadFromFile("res/images/tilesprite.png"))
		return;
}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	renderer.Draw(texture, sf::Vector2f(), sf::Vector2f(2, 2));
}