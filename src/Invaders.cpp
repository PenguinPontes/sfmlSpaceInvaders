#include "Invaders.h"

Invaders::Invaders()
    :m_stepGap(sf::seconds(0.4f))
{
    for (int x = 0 ; x < invaders::nInvadersX; x++)
        for (int y = 0; y < invaders::nInvadersY; y++)
        {
            float invaderX = x * Invader::Width + (Invader::GAP * x * 3) + Invader::Width;
            float invaderY = y * Invader::Height + (Invader::GAP * y) + Invader::Height * 4;
           
            Alien d = Alien(sf::Vector2f(invaderX, invaderY));
            d.setGridLocation(sf::Vector2i(x, y));
            d.Init();
            m_Aliens.emplace_back(d);
        }

    this->firstalienX = m_Aliens.front().getLocation().x;

    // Get the last invader in the row
    this->lastAlienX = (10 * Invader::Width + (Invader::GAP * 10 * 3) + Invader::Width) + Invader::Width;

}

Invaders::~Invaders()
{

}

void Invaders::TryToCollideWithProjectiles(std::vector<Projectile> &t_projectiles)
{
    for (auto &projectile : t_projectiles)
        for (auto &alien : m_Aliens)
        {
            if (!alien.isAlive() || !projectile.isActive())
                continue;

            if(alien.TryToCollideWith(projectile))
                this->m_stepGap -= sf::seconds(0.005);
        }
}

sf::Vector2f Invaders::getRandomBottomalien()
{

    std::srand(this->m_StepTimer.getElapsedTime().asMilliseconds());

    while (true)
    {

        int randomAlien = rand() % invaders::nInvadersX + 1;
        for (int x = 0; x < invaders::nInvadersX; x++) 
            for (int y = 4; y > -1 ; y--)
            {
                if ( this->m_Aliens.at(x * invaders::nInvadersY + y).getGridLocation().x == randomAlien && m_Aliens.at(x * invaders::nInvadersY + y).isAlive())
                {

                    return sf::Vector2f(
                        this->m_Aliens.at(x * invaders::nInvadersY + y).getPosition().x + Invader::Width / 2, 
                        this->m_Aliens.at(x * invaders::nInvadersY + y).getPosition().y + Invader::Height + 7);
                }
            }
    }
}

void Invaders::RenderAliens(sf::RenderWindow *window)
{
    for(Alien a : m_Aliens)
    {
        if (a.isAlive())
            a.Draw(window);
    }
}

void Invaders::TryToStep(sf::RenderWindow *window)
{

    if(m_StepTimer.getElapsedTime() > m_stepGap)
    {
    if (this->firstalienX < 10)
    {
        m_goDown = true;
        m_goLeft = false;
    }
    else if(this->lastAlienX > (window->getSize().x - 10) )
    {
        m_goDown = true; 
        m_goLeft = true;
    }
    else 
        m_goDown = false;

    float stepx = m_goLeft ? -10.00f : 10.00f;
    float stepy = m_goDown ?  10.00f : 00.00f;

        for(auto &a : m_Aliens)
        { 
            if(a.isAlive())
            {
                if(m_goDown)
                    a.Move(0,  stepy );
                else
                    a.Move(stepx ,stepy ); 
            }
        }

        lastAlienX += stepx * this->speed;
        firstalienX += stepx * this->speed;

        m_StepTimer.restart();
    }
}