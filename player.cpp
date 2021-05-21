#include "player.h"

using namespace sf;

Player::Player(String FileName, double Step, int x0, int y0)
{
	dir = direction_t::RIGHT;
	x = x0; y = y0;
	step = Step;
	CurrentFrame = 0;
	heroimage.loadFromFile(FileName);
	herotexture.loadFromImage(heroimage);
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, size_x, size_y));
	herosprite.setPosition(x0, y0);
}

void Player::update(double dx, double dy, double time, direction_t Dir)
{
	dir = Dir;
	CurrentFrame += (0.005 * time);
	if (CurrentFrame > 2) { CurrentFrame = 0; }
	herosprite.setTextureRect(IntRect(126 * int(CurrentFrame), 0, size_x, size_y));
	if ((x + dx > 0) && (x + dx < RES_WIDTH - 100) && (y + dy > 0) && (y + dy < RES_HEIGHT - 100)) {
		herosprite.move(dx, dy);
		x += dx;
		y += dy;
	}
}