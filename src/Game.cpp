#include "Game.h"
#include "Resources.h"

#include <filesystem>


void Begin(const sf::RenderWindow& window)
{
	for (auto& file : std::filesystem::directory_iterator("./res/images/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
		{
			Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
		}
	}
}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["tilesprite.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}