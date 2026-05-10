#include "Proyectil.h"

Proyectil::Proyectil(b2World& world, float x, float y)
{
    radio = 20.0f;
    color = ORANGE;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);

    body = world.CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radio;

    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.density = 1.0f;
    fixture.friction = 0.3f;
    fixture.restitution = 0.5f;

    body->CreateFixture(&fixture);
}

void Proyectil::Lanzar(float fuerzaX, float fuerzaY)
{
    body->SetAwake(true);

    body->SetLinearVelocity(
        b2Vec2(fuerzaX, fuerzaY)
    );
}

void Proyectil::Reiniciar()
{
    body->SetTransform(
        b2Vec2(120, 500),
        0
    );

    body->SetLinearVelocity(
        b2Vec2(0, 0)
    );

    body->SetAngularVelocity(0);

    body->SetAwake(true);
}

void Proyectil::Dibujar()
{
    b2Vec2 pos = body->GetPosition();

    DrawCircleV(
        { pos.x, pos.y },
        radio,
        color
    );

    DrawCircleLines(
        (int)pos.x,
        (int)pos.y,
        radio,
        BROWN
    );
}
b2Body* Proyectil::GetBody()
{
    return body;
}