#pragma once
#include <Box2D/box2d.h>
#include <Box2D/include/src/world.h>
#include "Box2D/include/src/body.h"
#include "box2d/include/src/shape.h"
//#include "box2d/include/samples/draw.h"
#include "Renderer.h"

class MyDebugDraw;

class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);
	static void DebugDraw(Renderer &renderer);

	static b2WorldDef worldDef;
	static b2WorldId worldId;
	static MyDebugDraw* debugDraw;
};

