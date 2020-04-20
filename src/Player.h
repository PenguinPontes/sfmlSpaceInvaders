#pragma once

#include "SFML/Graphics.hpp"
#include "Projectile.h"

class Player : public Collidable
{
private:

    sf::FloatRect body;
    bool m_isAlive = true;

    sf::Texture texture;
    sf::Sprite image;
public:

    Player();
    ~Player();

    virtual sf::Vector2f getPosition();
    virtual void onCollide(Collidable &other);

    void Input();
    void Draw(sf::RenderTarget *window);

    void TryToCollideProjectiles(std::vector<Projectile> &t_projectiles);

    sf::Vector2f getGunPosition();
    bool isAlive() {return m_isAlive;}

};
