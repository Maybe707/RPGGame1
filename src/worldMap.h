#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <SFML/Graphics.hpp>

class WorldMap : public sf::Drawable
{
	const int HEIGHT_MAP = 25;
	const int WIDTH_MAP = 40;
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::String TileMap[25] = 
	{
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s                                  0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};
public:
	WorldMap()
	{
		mapImage.loadFromFile("../res/Textures/map/ground_tiles.png");
		mapTexture.loadFromImage(mapImage);
	} 

	virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const override;

    void mapScrolling(float gameTime);
};

#endif
