#pragma once

#include "raylib.h"
#include <box2d.h>

class Proyectil
{
private:
    b2Body* body;
    float radio;
    Color color;

public:
    Proyectil(b2World& world, float x, float y);

    b2Body* GetBody();

    void Dibujar();

    void Lanzar(float fuerzaX, float fuerzaY);

    void Reiniciar();
};