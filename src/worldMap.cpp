#include "worldMap.h"

void WorldMap::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Sprite mapSprite;
	mapSprite.setTexture(mapTexture);
	for (int i = 0; i < HEIGHT_MAP; i++)
	for (int j = 0; j < WIDTH_MAP; j++)
	{
		if (TileMap[i][j] == ' ')  mapSprite.setTextureRect(sf::IntRect(32, 64, 64, 64));
		if (TileMap[i][j] == 's')  mapSprite.setTextureRect(sf::IntRect(32, 416, 64, 64));
		if ((TileMap[i][j] == '0')) mapSprite.setTextureRect(sf::IntRect(32, 288, 64, 64));


		mapSprite.setPosition(j * 62, i * 62);

		target.draw(mapSprite);
	}
}
