#include "enemy.h"



void Enemy::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(unitSprite);
}
