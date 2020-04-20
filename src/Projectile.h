#pragma once

#include "Collidable.h"

namespace projectile
{
    constexpr int width = 6;
    constexpr int height = 12;
}

class Projectile : public Collidable
{
private:

    sf::Vector2f m_moveVec;
    sf::RectangleShape body;
    bool m_isAlive;

public:
    Projectile(sf::Vector2i t_moveVec, sf::Vector2f t_Position);
    ~Projectile();

    virtual void onCollide(Collidable &other);
    virtual sf::Vector2f getPosition();

    void destroy();
    void update(sf::RenderTarget *window);

    inline bool isActive() { return m_isAlive;}

    inline void setPosition(sf::Vector2f t_position) { this->body.setPosition(t_position);}

};