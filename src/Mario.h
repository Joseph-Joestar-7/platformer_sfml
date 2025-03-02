#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Resources.h"
#include "Physics.h"

constexpr float M_PI = 22.0f / 7.0f;

class Mario
{
public:
	void Begin();
	void Update(float deltaTime);
	void Render(Renderer& renderer);
	sf::Vector2f position{};
	float angle{};

private:
	b2BodyId bodyId;
};

