#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"

void Begin(const sf::RenderWindow& window);

void Update(float deltaTime);
void Render(Renderer& renderer);

class Game
{
};

