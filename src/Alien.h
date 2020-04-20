#pragma once 

#include "SFML/Graphics.hpp"
#include "Collidable.h"

namespace Invader{
    constexpr static int Width = 50;
    constexpr static int Height = 32;
    constexpr static int GAP = 12;
};

class Alien : public Collidable
{
private:

    sf::Vector2f location;
    sf::Vector2f gridLocation;
    bool youGoodBro = true;

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Alien(sf::Vector2f t_location);
    ~Alien();

    virtual void onCollide(Collidable &other);
    virtual sf::Vector2f getPosition();

    void Draw(sf::RenderWindow *window);

    void Move(sf::Vector2f moveVec);
    void Move(int x, int y);

    void Init();


    void setGridLocation(sf::Vector2i t_location);

    sf::Vector2f getLocation() { return this->location;}
    sf::Vector2f getGridLocation() { return this->gridLocation;}

    bool isAlive() { return youGoodBro;}
};