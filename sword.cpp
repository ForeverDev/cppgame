#include "sword.h"

Entity_Sword::Entity_Sword(int x, int y): Entity(x, y) {
	draw_prec = 2;
	image = Image_Data("    #"
					   "   # "
					   "# #  "
					   " #   "
					   "# #  ");		
}

std::string Entity_Sword::get_on_top_string() {
	return "sword!!!";
}
