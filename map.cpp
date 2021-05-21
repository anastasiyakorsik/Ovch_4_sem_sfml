#include "map.h"

void Map::CreateMap()
{
	mapImage.loadFromFile("map.png");
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}