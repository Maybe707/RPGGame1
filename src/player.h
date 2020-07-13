#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <X11/X.h>
#include <algorithm>
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Unit.h"
#include "UnitsInterface.h"

class Player : public Unit
{   
protected:
    bool cameraFlag;
    sf::View cameraView; 
public:
    Player(const sf::String& imageStr, float coordX, float coordY,
    float wid, float heig, sf::View& cam) : cameraView(cam)
    {
        cameraFlag = false;
        speedX = 0.0f;
        speedY = 0.0f;
        mainSpeed = 0.0f;
        direction = 0;
        unitImage.loadFromFile(imageStr);
        unitTexture.loadFromImage(unitImage);
        unitSprite.setTexture(unitTexture);
        unitSprite.setPosition(200, 300);
        coordinateX = coordX;
        coordinateY = coordY;
        unitSprite.setTextureRect(sf::IntRect(0, 0, wid, heig));
    }
    
    void setCameraFlagToTrue()
    {
        cameraFlag = true;    
    }

    void setCameraFlagToFalse()
    {
        cameraFlag = false;
    }
    
    bool getCameraFlag()
    {
        return cameraFlag;
    }

    virtual void unitUpdate(float gameTime);

    virtual void unitAnimation(float gameTime); 
    
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;

    float getPlayerCoordinateX();

    float getPlayerCoordinateY();
};

#endif
