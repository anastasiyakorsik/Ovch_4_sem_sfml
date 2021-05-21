#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Brs
{
public:
	double x, y, velocity_x, velocity_y;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Brs();
	Brs(double x0, double y0, double velx, double vely);

	void update(double time);
};
