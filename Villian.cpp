#include "Villian.h"

using namespace sf;

Villian::Villian(String FileName, double Step, int x0, int y0)
{
	x = x0; y = y0;
	dir = direction_t::RIGHT;
	step = Step;
	villian_image.loadFromFile(FileName);
	villian_texture.loadFromImage(villian_image);
	villian_sprite.setTexture(villian_texture);
	villian_sprite.setTextureRect(IntRect(0, 0, size_x, size_y));
	villian_sprite.setPosition(x0, y0);
}

void Villian::update(double dx, double dy, double time)
{
	if (dir == direction_t::LEFT) {
		dx = -dx;
		dy = -dy;
	}

	if ((x + dx > 0) && (x + dx < RES_WIDTH) && (y + dy > 0) && (y + dy < RES_HEIGHT)) {
		villian_sprite.move(dx, dy);
		x += dx;
		y += dy;
	}
}