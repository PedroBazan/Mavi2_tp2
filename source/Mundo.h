#pragma once
#include <box2d.h>

class Mundo
{
private:
    b2World world;

public:
    Mundo();

    void Actualizar();

    b2World& GetWorld();
};
