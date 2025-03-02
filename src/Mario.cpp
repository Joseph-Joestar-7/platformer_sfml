#include "Mario.h"
#include <iostream>
const float movementSpeed = 20.0f;

void Mario::Begin()
{
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.position = { position.x, position.y};
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
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
	b2Body_SetAwake(bodyId, true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		b2Body_ApplyForceToCenter(bodyId, b2Vec2(move, 0.0f), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		b2Body_ApplyForceToCenter(bodyId, b2Vec2(-move, 0.0f), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		b2Body_ApplyForceToCenter(bodyId, b2Vec2(0.0f,-move), true);
	}


	position = sf::Vector2f(b2Body_GetPosition(bodyId).x, b2Body_GetPosition(bodyId).y);
	angle = b2Rot_GetAngle(b2Body_GetRotation(bodyId)) * (180.0f/M_PI);

	

}

void Mario::Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["megamanstanding.png"],position,
		sf::Vector2f(1.0f,1.5f),angle); 
}
