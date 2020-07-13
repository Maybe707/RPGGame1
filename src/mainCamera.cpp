#include "mainCamera.h"
#include "player.h"
#include <SFML/Graphics.hpp>

void MainCamera::setCameraFocus(int coordinateX, int coordinateY, bool cameraFlag)
{
    if(cameraFlag)
    {
        cameraView.setCenter(coordinateX, coordinateY);
    }
}

sf::View MainCamera::getCameraFocus()
{
    return cameraView;
}

void MainCamera::viewmap(float time, Player& plr)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		cameraView.move(0.1*time, 0);
        plr.setCameraFlagToFalse();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		cameraView.move(0, 0.1*time);
        plr.setCameraFlagToFalse();    
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
		cameraView.move(-0.1*time, 0);
        plr.setCameraFlagToFalse();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
    {
		cameraView.move(0, -0.1*time);
        plr.setCameraFlagToFalse();
	}
}
