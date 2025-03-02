#pragma once
#include <Box2D/box2d.h>
#include <Box2D/include/src/world.h>

class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);

	static b2WorldDef worldDef;
	static b2WorldId worldId;


};

