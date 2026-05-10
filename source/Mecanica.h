#pragma once

#include "raylib.h"
#include "Mundo.h"
#include "Proyectil.h"

class Mecanica
{
private:
    const int screenWidth = 1000;
    const int screenHeight = 600;

    Mundo mundo;

    Proyectil* proyectil;

public:
    Mecanica();

    ~Mecanica();

    void Ejecutar();

    void Actualizar();

    void Dibujar();
};
