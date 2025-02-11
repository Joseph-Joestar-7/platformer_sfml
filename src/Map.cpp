#include "Map.h"

Map::Map(float cellSize): cellSize(cellSize),grid()
{}

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

void Map::Draw(Renderer& renderer)
{
	int x = 0;
	for (const auto& column : grid)
	{
		int y = 0;
		for (const auto& cell : column)
		{
			if (cell)
			{
				renderer.Draw(Resources::textures["tilesprite.png"],
					sf::Vector2f(cellSize* x + cellSize/2.0f,
						cellSize * y + cellSize/ 2.0f),
					sf::Vector2f(cellSize,cellSize));
			}
			y++;
		}
		x++;
	}
}
