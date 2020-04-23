#include "Ufo.h"

Ufo::Ufo()
    :Collidable(100, 44)
{
    if (!m_texture.loadFromFile("res/sprites.png"))
        std::cout << "FAILED TO LOAD TEXTURE\n";
    m_image.setTexture(this->m_texture);
    m_image.setTextureRect(sf::IntRect(14,16,100,44));
    m_image.setPosition(-45, 10);
}

Ufo::~Ufo()
{

}

void Ufo::onCollide(Collidable &other)
{
    this->m_isActive = false;
}

void Ufo::Update(sf::RenderTarget* window, std::vector<Projectile> &t_projectiles)
{

    if (m_SpawnTimer.getElapsedTime() > sf::seconds(22.0f))
    {
        m_isActive = true;
        std::cout << "Ufo Respawnes\n";
        m_SpawnTimer.restart();
        this->m_image.setPosition(sf::Vector2f(-45, m_image.getPosition().y));
    }else if (this->m_image.getPosition().x > 1000) {
        m_isActive = false;
        this->m_image.setPosition(sf::Vector2f(-45, m_image.getPosition().y));
    }
    

    if (m_isActive)
    {
        m_image.move(2, 0);

        std::cout << this->m_image.getPosition().x << std::endl;

        for (Projectile &proj : t_projectiles)
        {
            if (proj.isActive())
            {
                this->TryToCollideWith(proj);
            }
            
        }

        window->draw(this->m_image);
    }
}
