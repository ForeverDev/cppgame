#include "player.h"

Player::Player(int x, int y): Entity(x, y) {
	image = Image_Data(" # # "
					   " $ $ "
					   "     "
					   "|   |"
					   "\\___/");
}
