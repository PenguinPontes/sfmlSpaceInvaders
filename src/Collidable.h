#pragma once
#include <SFML/Graphics.hpp>

class Collidable
{
    private:

        sf::Vector2f m_size;

    public:

    Collidable(int width, int height);

    // Return an object with the position and the size of the collidable object
    sf::FloatRect getBox();
    bool TryToCollideWith(Collidable &t_box);


    virtual sf::Vector2f getPosition() = 0;
    virtual void onCollide(Collidable &other) = 0;


};