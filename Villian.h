#ifndef _villian_H_
#define _villian_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game.h"

using namespace sf;

class Villian
{
public:
	const int size_x = 290, size_y = 350;
	int velocity_x;
	int velocity_y;
	direction_t dir;
	double step;
	Image villian_image;
	Texture villian_texture;
	Sprite villian_sprite;
	double x, y;
public:
	Villian(String FileName, double Step, int x0, int y0);

	void update(double dx, double dy, double time);
};


#endif