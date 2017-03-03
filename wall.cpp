#include <string>
#include "wall.h"

Entity_Wall::Entity_Wall(int x, int y): Entity(x, y) {
	draw_prec = 1;
	image = Image_Data("#####"
					   "#####"
					   "#####"
					   "#####"
					   "#####");
}

std::string Entity_Wall::get_on_top_string() {
	// the player can never be sitting on top of a wall,
	// so this is useless and will never be called
	return "";
}
