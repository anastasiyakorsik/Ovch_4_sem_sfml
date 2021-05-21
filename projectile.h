#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// Monitor the current state of the book
enum state_t {
	ERROR, FIRST, SECOND, THIRD, FOURTH, COUNT
};

class Projectile 
{
public:
	double x, y, velocity_x, velocity_y;
	
	sf::Image projimage;
	sf::Texture projtexture;
	sf::Sprite projsprite;
	
	Projectile();
	
	Projectile(double x0, double y0, double velx, double vely);
	// Change the current state of this projectile
	void changeState(state_t new_state);
	
	void update(double time);
};
