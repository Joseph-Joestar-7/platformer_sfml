#include "Game.h"
#include "Map.h"
#include <filesystem>

Map map(8.0f);
Camera camera(320.0f);
//Camera camera(500.0f);

const float movementSpeed = 180.0f;

void Begin(const sf::RenderWindow& window)
{
	for (auto& file : std::filesystem::directory_iterator("./res/images/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
		{
			Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
		}
	}

	sf::Image image;
	image.loadFromFile("res/images/world441.png");
	map.CreateFromImage(image);
	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Update(float deltaTime)
{
	float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.position.x += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.position.x -= move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		camera.position.y += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		camera.position.y -= move * deltaTime;
}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
	//renderer.Draw(Resources::textures["tilesprite.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}