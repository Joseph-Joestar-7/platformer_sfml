#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Resources.h"
class Mario
{
public:
	void Begin();
	void Update(float deltaTime);
	void Render(Renderer& renderer);
	sf::Vector2f position{};
	float angle{};
};

