#include "player.h"

float Player::getPlayerCoordinateX()
{
    return coordinateX;
}

float Player::getPlayerCoordinateY()
{
    return coordinateY;
}



void Player::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(unitSprite);
}

void Player::unitUpdate(float gameTime)
{
    switch (direction)
    {
        case 0:
            speedX = mainSpeed; speedY = 0;
            break;
        case 1:
            speedX = -mainSpeed; speedY = 0;
            break;
        case 2:
            speedX = 0; speedY = mainSpeed;
            break;
        case 3:
            speedX = 0; speedY = -mainSpeed;
            break;
    }

    coordinateX += speedX*gameTime;
    coordinateY += speedY*gameTime;

    mainSpeed = 0;
    unitSprite.setPosition(coordinateX, coordinateY);
}

void Player::unitAnimation(float gameTime)
{
    currentFrame += 0.005f*gameTime;
    if(currentFrame > 3)
        currentFrame -= 3;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction = 1; mainSpeed = 0.1;
        unitSprite.setTextureRect(sf::IntRect(32*int(currentFrame), 32, 32, 32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction = 0; mainSpeed = 0.1;
        unitSprite.setTextureRect(sf::IntRect(32*int(currentFrame), 64, 32, 32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        direction = 3; mainSpeed = 0.1;
        unitSprite.setTextureRect(sf::IntRect(32*int(currentFrame), 96, 32, 32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        direction = 2; mainSpeed = 0.1;
        unitSprite.setTextureRect(sf::IntRect(32*int(currentFrame), 0, 32, 32));
    }
}
