#include "player.h"

Entity_Player::Entity_Player(int x, int y): Entity(x, y) {
	draw_prec = 100;
	image = Image_Data(" # # "
					   " $ $ "
					   "     "
					   "|   |"
					   "\\___/");
}

std::string Entity_Player::get_on_top_string() {
	// only exists for compatibility.... the player
	// can never be ontop of itself!
	return "";
}
