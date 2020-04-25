#include "Player.h"

Player::Player()
    :Collidable(99 * 0.7f, 59 * 0.7f)
{


    texture.loadFromFile("res/sprites.png");

    image.setPosition(500, 760);
    image.setTexture(texture);
    image.setTextureRect(sf::IntRect(11,84, 99,59));
    image.setScale(0.7f, 0.7f);

    this->shootBuffer.loadFromFile("res/sounds/player_shoot.wav");
    this->shootSound.setBuffer(shootBuffer);
    shootSound.setVolume(30.00f);

}

Player::~Player()
{

}

sf::Vector2f Player::getPosition()
{
    return this->image.getPosition();
}

void Player::onCollide(Collidable &other)
{
    this->m_isAlive = false;
}

void Player::TryToCollideProjectiles(std::vector<Projectile> &t_projectiles)
{
    for (auto &p : t_projectiles)
    {
        p.TryToCollideWith(*this);
    }
    
}

void Player::Input()
{
    if (this->m_isAlive)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            image.move(-5, 0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            image.move(5, 0);
    }
    

}

sf::Vector2f Player::getGunPosition()
{
    return sf::Vector2f(image.getPosition().x + 33, image.getPosition().y - 20);
}

void Player::Draw(sf::RenderTarget *window)
{
    window->draw(image);
}