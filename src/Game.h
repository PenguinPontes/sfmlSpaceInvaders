#pragma once 

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Player.h"
#include "Invaders.h"
#include "Projectile.h"

#include <random>

namespace space_invaders
{
    const int InvaderWidth = 20;
    const int InvaderHeight = 20;
    const int GAP = 10;

}
class Game
{
private:

    sf::RenderWindow *window;
    const int nScreenWidth;
    const int nScreenHeigth; 

    std::vector<Projectile> m_projectiles;

    Player *m_player;
    Invaders *m_invaders;

    sf::Clock m_stepTime;
    sf::Time m_stepGap;

    sf::Clock m_shootTime;
    sf::Time m_shootGap;

    sf::Clock m_alienShootTime;
    sf::Time m_alienShootGap;
public:

    Game(int nScreenWidth, int nScreenHeigth);
    ~Game();

    void playerShoot();
    void alienShoot(Invaders *t_invaders);
    void UpdateProjectiles();

    void Run();

    void HandleEvents();
    void HandleInput();

    bool IsRunning();


};