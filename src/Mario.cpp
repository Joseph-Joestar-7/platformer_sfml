#include "Mario.h"

const float movementSpeed = 3.0f;

void Mario::Begin()
{
}

void Mario::Update(float deltaTime)
{
	float move = movementSpeed;

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		position.x += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		position.x -= move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		position.y += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		position.y -= move * deltaTime;*/

}

void Mario::Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["megamanstanding.png"],position,
		sf::Vector2f(1.0f,2.0f));
}
