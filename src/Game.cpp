#include "Game.h"

Game::Game(int t_ScreenWidth, int t_ScreenHeigth) 
    : nScreenHeigth(t_ScreenHeigth), nScreenWidth(t_ScreenWidth), 
      m_stepGap(sf::seconds(0.5f)),
      m_alienShootGap(sf::seconds(1.5f)),
      m_shootGap(sf::seconds(0.9f))
{
    this->m_player = new Player;

    window = new sf::RenderWindow(sf::VideoMode(nScreenWidth, nScreenHeigth), "Milk Invader", sf::Style::Titlebar);
    window->setPosition(sf::Vector2i(100,100));
};

Game::~Game()
{
    delete window;
    delete m_player;
};

void Game::Run()
{

    Invaders invaders;

    while (IsRunning() && m_player->isAlive())
    {

        this->HandleEvents();
        this->HandleInput();

        window->clear();


        m_player->Input();


        m_player->TryToCollideProjectiles(m_projectiles);

        this->playerShoot();
        this->alienShoot(&invaders);
        this->UpdateProjectiles();

        invaders.TryToStep(window);
        invaders.TryToCollideWithProjectiles(m_projectiles);

        m_player->Draw(window);
        invaders.RenderAliens(window);

        window->display();
    }
    
}

void Game::UpdateProjectiles()
{
    for (auto &p : m_projectiles)
        p.update(window);
}

void Game::alienShoot(Invaders* t_invaders)
{
    if ( m_alienShootTime.getElapsedTime() > m_alienShootGap)
    {
        std::srand(this->m_stepTime.getElapsedTime().asMilliseconds());

        int randomAlien = rand() % invaders::nInvadersX + 1;

        Projectile proj(sf::Vector2i(0,1), sf::Vector2f(-10, -10));

        for ( Alien &p : t_invaders->getAliens()) 
        {
            if ( p.getGridLocation().x == randomAlien && p.isAlive())
            {
                proj.setPosition(sf::Vector2f(p.getPosition().x + Invader::Width / 2, p.getPosition().y + Invader::Height + 7));
            }
        }

        m_projectiles.push_back(proj);
        m_alienShootTime.restart();
    }
}
void Game::playerShoot()
{

    if (m_shootTime.getElapsedTime() > m_shootGap && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_projectiles.push_back(Projectile({0,-1}, m_player->getGunPosition()));
        m_shootTime.restart();
    }
}
void Game::HandleEvents()
{
    sf::Event event;

    window->pollEvent(event);

    if (event.type = sf::Event::EventType::Closed)
        window->close(); 
}

void Game::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window->close();
    
}

bool Game::IsRunning()
{
    if (window->isOpen())
        return true;
    else
        return false;
};

