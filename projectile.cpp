#include "projectile.h"

using namespace sf;

Projectile::Projectile() {
	x = -1000; y = -1000;
	velocity_x = 0;
	velocity_y = 0;
	projimage.loadFromFile("obshephys1.png");
	projtexture.loadFromImage(projimage);
	projsprite.setTexture(projtexture);
	projsprite.setTextureRect(IntRect(0, 0, 70, 100));
	projsprite.setPosition(x, y);
}

Projectile::Projectile(double x0, double y0, double velx, double vely)
{
	x = x0; y = y0;
	velocity_x = velx;
	velocity_y = vely;
	projimage.loadFromFile("images/obshephys1.jpg");
	projtexture.loadFromImage(projimage);
	projsprite.setTexture(projtexture);
	projsprite.setTextureRect(IntRect(0, 0, 126, 123));
	projsprite.setPosition(x0, y0);
}

void Projectile::update(double time)
{ 
	projsprite.move(velocity_x * time, velocity_y * time);
}

void Projectile::changeState(state_t new_state) {
	switch (new_state) {
		case state_t::FIRST:
			projimage.loadFromFile("obshephys1.png");
			projtexture.loadFromImage(projimage);
			projsprite.setTexture(projtexture);
			break;
		case state_t::SECOND:
			projimage.loadFromFile("obshephys2.png");
			projtexture.loadFromImage(projimage);
			projsprite.setTexture(projtexture);
			break;
		case state_t::THIRD:
			projimage.loadFromFile("obshephys3.png");
			projtexture.loadFromImage(projimage);
			projsprite.setTexture(projtexture);
			break;
		case state_t::FOURTH:
			projimage.loadFromFile("obshephys4.png");
			projtexture.loadFromImage(projimage);
			projsprite.setTexture(projtexture);
			break;
		default:
			throw std::runtime_error("Unknown state of the projectile!");
	}
}