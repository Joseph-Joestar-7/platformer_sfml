#pragma once
#include "vendor/box2d/src/world.h" 

class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);
private:
	static b2World world;

};

