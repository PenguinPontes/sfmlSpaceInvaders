#include "Collidable.h"

Collidable::Collidable(int width ,int height)
    : m_size(width, height)
{

}

bool Collidable::TryToCollideWith(Collidable &t_box)
{
    if (getBox().intersects(t_box.getBox()))
    {
        onCollide(t_box);
        t_box.onCollide(*this);
        return true;
    }
    return false;
}

sf::FloatRect Collidable::getBox() 
{
    return {getPosition().x, getPosition().y, m_size.x, m_size.y};
}