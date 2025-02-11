#pragma once

#include <vector>

class Map
{
public:
	void CreateCheckerboard(size_t width, size_t height);
	std::vector<std::vector<int>> grid;

};

