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

sf::Vector2f Map::CreateFromImage(const sf::Image& image)
{
	grid.clear();
	grid = std::vector(image.getSize().x, std::vector(image.getSize().y, 0));

	sf::Vector2f marioPos{};

	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[y].size(); y++)
		{
			sf::Color color = image.getPixel(x, y);
			if (color == sf::Color::Black)
				grid[x][y] = 1;
			else if (color == sf::Color::Red)
			{
				marioPos = sf::Vector2f(cellSize * x + cellSize / 2.0f,
					cellSize * y + cellSize / 2.0f);
			}
		}
	}
	return marioPos;
}

sf::Vector2f Map::CreateFromFile(const std::string& filePath)
{
    grid.clear();
    sf::Vector2f marioPos{};  // Default Mario position

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open map file: " << filePath << std::endl;
        return marioPos;
    }

    // Read each non-empty line from the file.
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
            lines.push_back(line);
    }
    file.close();

    if (lines.empty())
    {
        std::cerr << "Error: Map file is empty: " << filePath << std::endl;
        return marioPos;
    }

    // Determine the dimensions.
    size_t height = lines.size();        // number of rows
    size_t width = lines[0].size();        // assume all rows are equal in length

    // Initialize the grid. Note that the grid is stored as grid[x][y].
    grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));

    // Parse the file:
    // Each line is a row (y-coordinate) and each character in the line is a column (x-coordinate).
    for (size_t y = 0; y < height; ++y)
    {
        if (lines[y].size() != width)
        {
            std::cerr << "Warning: Row " << y << " has a different length. Using the first row's length (" << width << ").\n";
        }
        for (size_t x = 0; x < width; ++x)
        {
            char ch = lines[y][x];
            if (ch == '0')
            {
                // Empty space; nothing to do (cell remains 0)
                grid[x][y] = 0;
            }
            else if (ch == '1')
            {
                // Place a tile.
                grid[x][y] = 1;

                b2BodyDef bodyDef= b2DefaultBodyDef();
                bodyDef.position = {cellSize*x + cellSize/2.0f, cellSize* y + cellSize/2.0f};
                //b2Body* body = Physics::world.CreateBody(&bodyDef);

                b2BodyId bodyId = b2CreateBody(Physics::worldId, &bodyDef);
                b2Polygon shape{};
                shape = b2MakeBox(cellSize/2.0f, cellSize/2.0f);
                b2ShapeDef shapeDef= b2DefaultShapeDef();

                b2CreatePolygonShape(bodyId, &shapeDef, &shape);
                
            }
            else if (ch == '2')
            {
                // Set Mario's initial position.
                // In our grid, we treat it as an empty space.
                grid[x][y] = 0;
                marioPos = sf::Vector2f(cellSize * x + cellSize / 2.0f,
                    cellSize * y + cellSize / 2.0f);
            }
            else
            {
                // Unknown character, treat as empty.
                grid[x][y] = 0;
            }
        }
    }
    std::cout << marioPos.x <<" "<<marioPos.y << std::endl;
    return marioPos;
}

