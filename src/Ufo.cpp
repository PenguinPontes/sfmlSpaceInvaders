#include "Ufo.h"

Ufo::Ufo()
    :Collidable(100, 44),
     m_isActive(false)
{
    m_texture.loadFromFile("res/sprites.png");
    m_image.setTexture(this->m_texture);
    m_image.setTextureRect(sf::IntRect(14,16,100,44));
    m_image.setPosition(-45, 10);
    this->m_SpawnTimer.restart();
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

        this->m_ufoSound.openFromFile("res/sounds/ufoMusic.ogg");

        m_ufoSound.setLoop(true);
        m_ufoSound.setVolume(50.00f);

        this->m_ufoSound.play();

        m_isActive = true;

        m_SpawnTimer.restart();

        this->m_image.setPosition(sf::Vector2f(-45, m_image.getPosition().y));

    }else if (this->m_image.getPosition().x > 1000) {

        m_isActive = false;

        this->m_image.setPosition(sf::Vector2f(-45, m_image.getPosition().y));
        
        this->m_ufoSound.stop();
    }
    

    if (m_isActive)
    {
        m_image.move(2, 0);

        for (Projectile &proj : t_projectiles)
        {
            if (proj.isActive())
            {
                this->TryToCollideWith(proj);
            }
            
        }

        window->draw(this->m_image);
    }else
    {
        this->m_ufoSound.stop();
    }
    
}
