#include "-3brs.h"
using namespace sf;

Brs::Brs() {
	x = -1000; y = -1000;
	velocity_x = 0;
	velocity_y = 0;
	image.loadFromFile("-3brs.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 100, 100));
	sprite.setPosition(x, y);
}

Brs::Brs(double x0, double y0, double velx, double vely)
{
	x = x0; y = y0;
	velocity_x = velx;
	velocity_y = vely;
	image.loadFromFile("-3brs.jpg");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 100, 100));
	sprite.setPosition(x0, y0);
}

void Brs::update(double time)
{
	sprite.move(velocity_x * time, velocity_y * time);
}
