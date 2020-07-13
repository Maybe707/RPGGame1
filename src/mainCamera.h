#ifndef MAINCAMERA_H
#define MAINCAMERA_H

#include "SFML/Graphics.hpp"
#include "player.h"

class MainCamera
{
    sf::View cameraView;
public:
    MainCamera(sf::View& cam) : cameraView(cam)
    {}
    void setCameraFocus(int coordinateX, int coordinateY, bool cameraFlag);
    sf::View getCameraFocus();

    void viewmap(float time, Player& plr);
};
#endif
