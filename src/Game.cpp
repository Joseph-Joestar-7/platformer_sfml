#include "Game.h"
#include "Map.h"
#include <filesystem>

Map map;
Camera camera(320.0f);

void Begin(const sf::RenderWindow& window)
{
	for (auto& file : std::filesystem::directory_iterator("./res/images/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
		{
			Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
		}
	}

	map.CreateCheckerboard(10, 10);
	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
	//renderer.Draw(Resources::textures["tilesprite.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}