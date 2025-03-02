#include "Mario.h"

const float movementSpeed = 3.0f;

void Mario::Begin()
{
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.position = { position.x, position.y};
	bodyDef.type = b2_dynamicBody;
	bodyId = b2CreateBody(Physics::worldId, &bodyDef);
	b2Polygon shape{};
	shape = b2MakeBox(0.5f,0.75f);
	b2ShapeDef shapeDef = b2DefaultShapeDef();
	shapeDef.density = 1.0f;
	shapeDef.friction = 0.3f;

	b2CreatePolygonShape(bodyId, &shapeDef, &shape);
}

void Mario::Update(float deltaTime)
{
	float move = movementSpeed;

	position = sf::Vector2f(b2Body_GetPosition(bodyId).x, b2Body_GetPosition(bodyId).y);
	angle = b2Rot_GetAngle(b2Body_GetRotation(bodyId)) * (180.0f/M_PI);


	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		position.x += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		position.x -= move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		position.y += move * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		position.y -= move * deltaTime;*/

}

void Mario::Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["megamanstanding.png"],position,
		sf::Vector2f(1.0f,1.5f));
}
