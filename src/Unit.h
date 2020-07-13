#ifndef RPGGAME_UNIT_H
#define RPGGAME_UNIT_H

#include <SFML/Graphics.hpp>
#include "UnitsInterface.h"

class Unit : public UnitsInterface
{
protected:
    sf::Sprite unitSprite;
    sf::Texture unitTexture;
    sf::Image unitImage;
    float coordinateX, coordinateY, width, height, speedX, speedY, mainSpeed, currentFrame = 0.0f;
    int direction;
    sf::String unitString;
public:

    sf::Sprite& getUnitSprite();

    float getplayercoordinateX()
    {
        return coordinateX;
    }
    float getplayercoordinateY()
    {
        return coordinateY;
    }
};

#endif
