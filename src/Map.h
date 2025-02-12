#pragma once
#include "Renderer.h"
#include "Resources.h"
#include <vector>
#include <fstream>
#include <iostream>

class Map
{
public:
	Map(float cellSize = 32.0f);
	void CreateCheckerboard(size_t width, size_t height);
	void Draw(Renderer& renderer);
	sf::Vector2f CreateFromImage(const sf::Image& image);
	sf::Vector2f CreateFromFile(const std::string& filePath);
	std::vector<std::vector<int>> grid;
	float cellSize;
};

