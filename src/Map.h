#pragma once
#include "Renderer.h"
#include "Resources.h"
#include <vector>

class Map
{
public:
	Map(float cellSize = 32.0f);
	void CreateCheckerboard(size_t width, size_t height);
	void Draw(Renderer& renderer);
	void CreateFromImage(const sf::Image& image);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

