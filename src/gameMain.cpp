#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "SFML/Window/Keyboard.hpp"
#include "player.h"
#include "worldMap.h"
#include "enemy.h"
#include "mainCamera.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "RPGGame");
    sf::View cameraView;
    cameraView.reset(sf::FloatRect(0, 0, 640, 480));

    Player playerHero("../res/Textures/hero.png", 200, 300, 32, 32, cameraView);

    WorldMap map;

    sf::Clock gameClock;
   
    MainCamera playerCamera(cameraView);     
    sf::Event event;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        float gameTime = gameClock.getElapsedTime().asMicroseconds();
        gameClock.restart();
        gameTime /= 800;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
             switch(event.key.code)
                 {
                 case sf::Keyboard::D:
                 case sf::Keyboard::S:
                 case sf::Keyboard::A:
                 case sf::Keyboard::W:
                 playerHero.setCameraFlagToTrue();
                 break;
                 default:
                 break;
            }
 
        }
    }
        
        playerHero.unitAnimation(gameTime);
        playerHero.unitUpdate(gameTime);
        playerCamera.viewmap(gameTime, playerHero);
        playerCamera.setCameraFocus(playerHero.getPlayerCoordinateX(), playerHero.getPlayerCoordinateY(), playerHero.getCameraFlag());
        
        window.setView(playerCamera.getCameraFocus());
        window.clear();

        window.draw(map);

        window.draw(playerHero);
        window.display();
    }

    return EXIT_SUCCESS;
}
