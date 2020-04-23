#pragma once

#include "SFML/Graphics.hpp"
#include "Projectile.h"
#include "Alien.h"

#include <random>
#include <vector>

namespace invaders
{
    constexpr uint16_t nInvadersX = 11;
    constexpr uint16_t nInvadersY = 5;
}
class Invaders
{
private:

    std::vector<Alien> m_Aliens;

    sf::Clock clock;

    bool m_goLeft = true;
    bool m_goDown = false;

    float speed = 1.0f;

    sf::Clock m_StepTimer;
    sf::Time m_stepGap;

    int lastAlienX, firstalienX;

public:
    Invaders();
    ~Invaders();


    void RenderAliens(sf::RenderWindow *window);
    void TryToStep(sf::RenderWindow *window);
    void KillAlien();

    void TryToCollideWithProjectiles(std::vector<Projectile> &t_projectiles);

    std::vector<Alien> getAliens(){return m_Aliens;}
};