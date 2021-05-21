#pragma once
#ifndef _map_H_
#define _map_H_
#include <SFML/Graphics.hpp>

using namespace sf;

const int height = 12;
const int width = 21;

class Map
{
public:
	Image mapImage;
	Texture mapTexture;
	Sprite mapSprite;

	void CreateMap();

	sf::String TileMap[height] = {
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
		"000000000000000000000",
	};
};


#endif
