#ifndef _player_H_
#define _player_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game.h"

using namespace sf;

class Player 
{
private:
	const int size_x = 126, size_y = 123;
public:
	double step;
	double CurrentFrame;
	Image heroimage;
	Texture herotexture;
	Sprite herosprite;
	double x, y;
	direction_t dir;
	
	Player(String FileName, double Step, int x0, int y0);
	
	void update(double dx, double dy, double time, direction_t Dir);
};


#endif
