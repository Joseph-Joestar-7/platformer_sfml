#include "Map.h"

Map::Map(float cellSize): cellSize(cellSize),grid()
{}

void Map::CreateCheckerboard(size_t width, size_t height)
{
	grid = std::vector(width, std::vector(height, 0));

	for (size_t x = 0; x < width; ++x)
	{
		for (size_t y = 0; y < height; ++y)
		{
			grid[x][y] = (x + y) % 2;  
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
			if (!cell)
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

void Map::CreateFromImage(const sf::Image& image)
{
	grid.clear();
	grid = std::vector(image.getSize().x, std::vector(image.getSize().y, 0));

	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[y].size(); y++)
		{
			sf::Color color = image.getPixel(x, y);
			if (color == sf::Color::Black)
				grid[x][y] = 1;
		}
	}

}
