#ifndef RPGGAME_unit_H
#define RPGGAME_unit_H

#include "UnitsInterface.h"
#include <SFML/Graphics.hpp>
#include "Unit.h"

class Enemy : public Unit
{
public:
    Enemy(const sf::String& imageStr, float coordX, float coordY,
           float wid, float heig)
    {
        speedX = 0.0f;
        speedY = 0.0f;
        mainSpeed = 0.0f;
        direction = 0;
        unitImage.loadFromFile(imageStr);
        unitTexture.loadFromImage(unitImage);
        unitSprite.setTexture(unitTexture);
        unitSprite.setPosition(350, 250);
        coordinateX = coordX;
        coordinateY = coordY;
        unitSprite.setTextureRect(sf::IntRect(0, 0, wid, heig));
    }

    void draw (sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
