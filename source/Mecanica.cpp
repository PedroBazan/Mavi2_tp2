#include "Mecanica.h"

Mecanica::Mecanica()
{
    InitWindow(
        screenWidth,
        screenHeight,
        "MAVI II - Catapulta"
    );

    SetTargetFPS(60);

    proyectil = new Proyectil(
        mundo.GetWorld(),
        120,
        screenHeight - 100
    );

    // suelo
    b2BodyDef groundDef;
    groundDef.type = b2_staticBody;

    groundDef.position.Set(
        screenWidth / 2.0f,
        screenHeight - 40
    );

    b2Body* groundBody =
        mundo.GetWorld().CreateBody(&groundDef);

    b2PolygonShape groundShape;

    groundShape.SetAsBox(
        screenWidth / 2.0f,
        20
    );

    groundBody->CreateFixture(
        &groundShape,
        0.0f
    );
}

Mecanica::~Mecanica()
{
    delete proyectil;

    CloseWindow();
}

void Mecanica::Ejecutar()
{
    while (!WindowShouldClose())
    {
        Actualizar();

        Dibujar();
    }
}

void Mecanica::Actualizar()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        proyectil->Reiniciar();

        proyectil->Lanzar(
            110.0f,
            -70.0f
        );
    }

    mundo.Actualizar();
}

void Mecanica::Dibujar()
{
    BeginDrawing();

    ClearBackground({ 110,100,215,255 });

    // suelo
    DrawRectangle(
        0,
        screenHeight - 60,
        screenWidth,
        40,
        DARKGREEN
    );

    // catapulta
    DrawLine(
        80,
        screenHeight - 80,
        140,
        screenHeight - 120,
        DARKBROWN
    );

    proyectil->Dibujar();

    DrawText(
        "ESPACIO = lanzar proyectil",
        20,
        20,
        25,
        RAYWHITE
    );

    EndDrawing();
}
