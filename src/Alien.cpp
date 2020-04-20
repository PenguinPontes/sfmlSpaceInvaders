#include "Alien.h"


Alien::Alien(sf::Vector2f t_location)
    :location(t_location),
     Collidable(Invader::Width ,Invader::Height)
{
}
Alien::~Alien()
{};

sf::Vector2f Alien::getPosition()
{
    return this->location;
}

void Alien::onCollide(Collidable &other)
{
    this->youGoodBro = false;
}

void Alien::Init()
{
    if (this->gridLocation.y == 0 )
        texture.loadFromFile("res/sprites.png", sf::IntRect(43,1509,43,27));
    else if(this->gridLocation.y == 1)
        texture.loadFromFile("res/sprites.png", sf::IntRect(43,1509,43,27));
    else if(this->gridLocation.y == 2)
        texture.loadFromFile("res/sprites.png", sf::IntRect(45, 1557,39,26));
    else if( this->gridLocation.y == 3)
        texture.loadFromFile("res/sprites.png", sf::IntRect(45, 1557,39,26));
    else if(this->gridLocation.y == 4)
        texture.loadFromFile("res/sprites.png", sf::IntRect(169,1514,39,26));

    sprite.setTexture(texture, true);
    sprite.setScale(1.3f, 1.3f);
}

void Alien::setGridLocation(sf::Vector2i t_location)
{
    this->gridLocation.x = t_location.x;
    this->gridLocation.y = t_location.y;
}

void Alien::Draw(sf::RenderWindow *window)
{
    sprite.setPosition(this->getPosition().x, this->getLocation().y),
    window->draw(sprite);
}

void Alien::Move(sf::Vector2f moveVec)
{
    this->location.x += moveVec.x;
    this->location.y += moveVec.y;
}

void Alien::Move(int x, int y)
{
    this->location.x += x;
    this->location.y += y;
}