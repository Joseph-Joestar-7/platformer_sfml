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
MyDebugDraw* Physics::debugDraw{};

class MyDebugDraw :public Draw
{
public:
    MyDebugDraw(sf::RenderTarget& target):target(target)
    {
        
    }

    void DrawPolygon(const b2Vec2* vertices, int32_t vertexCount, b2HexColor color)
    {
        sf::ConvexShape shape(vertexCount);
        for (size_t i = 0; i < vertexCount; i++)
        {
            shape.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
        }

        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            255);                 // Alpha (fully opaque)
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(1.0f);
        shape.setOutlineColor(sfColor);
        target.draw(shape);
    }

    void DrawSolidPolygon(b2Transform transform, const b2Vec2* vertices, int32_t vertexCount, float radius, b2HexColor color)
    {
        sf::ConvexShape shape(vertexCount);
        for (size_t i = 0; i < vertexCount; i++)
        {
            shape.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
        }

        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            255);                 // Alpha (fully opaque)
        shape.setFillColor(sf::Color::Transparent);
    
        target.draw(shape); 
    }

    void DrawCircle(b2Vec2 center, float radius, b2HexColor color)
    {
        sf::CircleShape circle(radius);
        circle.setPosition(center.x, center.y);
        circle.setOrigin(radius / 2.0f, radius / 2.0f);

        // Convert b2HexColor to sf::Color
        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            255);                 // Alpha (fully opaque)
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineThickness(1.0f);
        circle.setOutlineColor(sfColor);
        target.draw(circle);
    }

    void DrawSolidCircle(b2Transform transform, b2Vec2 center, float radius, b2HexColor color)
    {
        sf::CircleShape circle(radius);
        circle.setPosition(center.x,center.y);
        circle.setOrigin(radius / 2.0f, radius/ 2.0f);

        // Convert b2HexColor to sf::Color
        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            ((color >> 24) & 0xFF) * 80 / 255); // Alpha 

        circle.setFillColor(sfColor);
        target.draw(circle);

        b2Vec2 axis = b2Mul(transform.p, { 1.0f, 0.0f });
        b2Vec2 p = center + (radius * axis);
        DrawSegment(center, p, color);
    }

    void DrawTransform(b2Transform transform)
    {
        b2Vec2 p = transform.p;

        // Extract X and Y axes from rotation
        b2Vec2 xAxis = { transform.q.c, transform.q.s };  // (cos, sin) for X-axis 
        b2Vec2 yAxis = { -transform.q.s, transform.q.c }; // (-sin, cos) for Y-axis 

        // Scale the axes for visibility
        b2Vec2 px = p + (0.5f * xAxis); 
        b2Vec2 py = p + (0.5f * yAxis);

        DrawSegment(p, px, b2_colorRed);
        DrawSegment(p, py, b2_colorGreen);
    }

    void DrawSegment(b2Vec2 p1, b2Vec2 p2, b2HexColor color)
    {
        sf::VertexArray va(sf::Lines, 2);
        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            ((color >> 24) & 0xFF)); // Alpha 

        va[0].position = sf::Vector2f(p1.x, p1.y);
        va[0].color = sfColor;

        va[1].position = sf::Vector2f(p2.x, p2.y);
        va[1].color = sfColor;

        target.draw(va);

    }

    void DrawPoint(b2Vec2 p, float size, b2HexColor color)
    {
        sf::CircleShape circle(size);
        circle.setPosition(p.x, p.y);
        circle.setOrigin(size / 2.0f,size/2.0f);

        // Convert b2HexColor to sf::Color
        sf::Color sfColor((color >> 16) & 0xFF, // Red
            (color >> 8) & 0xFF,  // Green
            (color) & 0xFF,       // Blue
            255);                 // Alpha (fully opaque)

        circle.setFillColor(sfColor);
        target.draw(circle);
    }


private:
    sf::RenderTarget& target;

};

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
    if (!debugDraw)
    {
        debugDraw = new MyDebugDraw(renderer.target);
        
    }
}
