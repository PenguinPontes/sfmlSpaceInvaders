#pragma once

#include "SFML/Graphics.hpp"
#include "Projectile.h"

class Ufo : public Collidable
{
private:


public:
    Ufo(/* args */);
    ~Ufo();

    void  onCollide(Collidable & other);
    sf::Vector2f getPosition();
};
