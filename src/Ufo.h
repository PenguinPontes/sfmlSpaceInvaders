#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Projectile.h"

class Ufo : public Collidable
{
private:
    sf::Texture m_texture;
    sf::Sprite m_image;

    bool m_isActive;

    sf::Clock m_SpawnTimer;

    sf::Music m_ufoSound;
public:
    Ufo(/* args */);
    ~Ufo();

    void  onCollide(Collidable & other);
    sf::Vector2f getPosition() { return m_image.getPosition(); };

    void TryToCollideWithProjectiles(std::vector<Projectile> &t_projectiles);
    void Update(sf::RenderTarget *window, std::vector<Projectile> &t_projectiles);

    inline bool isAlive() { return this->m_isActive; } 
};
