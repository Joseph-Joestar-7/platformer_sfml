#include "Game.h"
#include "Map.h"
#include <filesystem>
#include "Mario.h"

Map map(12.0f);
Camera camera(320.0f);
Mario mario;

void Begin(const sf::RenderWindow& window)
{
	for (auto& file : std::filesystem::directory_iterator("./res/images/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
		{
			Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
		}
	}

	//sf::Image image;
	//image.loadFromFile("res/images/world441.png");
	//mario.position = map.CreateFromImage(image);

	mario.position= map.CreateFromFile("res/map/map.txt");

}

void Update(float deltaTime)
{
	mario.Update(deltaTime);
	camera.position = mario.position;	
}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
	mario.Render(renderer);
	//renderer.Draw(Resources::textures["tilesprite.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}