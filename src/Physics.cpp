#include "Physics.h"

//b2World Physics::world{ b2Vec2(0.0f,-9.2f) }; 

static b2WorldDef CreateWorldDef()
{
    b2WorldDef def = b2DefaultWorldDef();
    def.gravity = {0.0f, 9.2f};  // Set gravity
    return def;
}

b2WorldDef Physics::worldDef = CreateWorldDef();
b2WorldId Physics::worldId = b2CreateWorld(&Physics::worldDef);

void Physics::Init()
{
    CreateWorldDef();
}

void Physics::Update(float deltaTime)
{
    b2World_Step(worldId, deltaTime,1 );
}

void Physics::DebugDraw(Renderer& renderer)
{

}
