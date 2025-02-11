#include "Map.h"

void Map::CreateCheckerboard(size_t width, size_t height)
{
	grid = std::vector(width, std::vector(height,0));

	int last =0 ;
	for (auto& column : grid)
	{
		for (auto& cell : column)
		{
			cell = ~last;
			last = cell;
		}
	}
}
