#include "Projectile.h"

Projectile::Projectile(sf::Vector2i t_moveVec, sf::Vector2f t_Position)
    : Collidable(projectile::width,projectile::height),
      m_moveVec(t_moveVec),
      m_isAlive(true)
{
    this->body.setFillColor(sf::Color::White);
    this->body.setPosition(t_Position.x, t_Position.y);
    this->body.setSize(sf::Vector2f(projectile::width, projectile::height));
}

Projectile::~Projectile()
{
}

sf::Vector2f Projectile::getPosition()
{
    return body.getPosition();
}

void Projectile::destroy()
{
    m_isAlive = false;
}
void Projectile::onCollide(Collidable &other)
{
    destroy();
}

void Projectile::update(sf::RenderTarget *window)
{
    if(m_isAlive)
    {
        float speed = 6.6f * (float)this->m_moveVec.y ;
        body.move(0, speed);

        if (body.getPosition().y <= 0 || body.getPosition().y >= 1000) 
            destroy();

        this->body.move(m_moveVec.x, m_moveVec.y);
        window->draw(body);
    }
}