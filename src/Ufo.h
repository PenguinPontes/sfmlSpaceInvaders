#pragma once

#include "SFML/Graphics.hpp"
#include "Projectile.h"
#include <iostream>

class Ufo : public Collidable
{
private:

    sf::Texture m_texture;
    sf::Sprite m_image;

    bool m_isActive = true;

    sf::Clock m_SpawnTimer;
public:
    Ufo(/* args */);
    ~Ufo();

    void  onCollide(Collidable & other);
    sf::Vector2f getPosition() { return m_image.getPosition(); };

    void TryToCollideWithProjectiles(std::vector<Projectile> &t_projectiles);
    void Update(sf::RenderTarget *window, std::vector<Projectile> &t_projectiles);

    inline bool isAlive() { return this->m_isActive; } 
};
