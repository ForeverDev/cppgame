#include "string.h"
#include "game.h"

Game_State::Game_State() {
	player = new Player;
	player->position.x = 1;
	player->position.y = 0;
	add_entity(player);
}

void Game_State::main_loop() {

	while (true) {
		render_screen();
		getchar();
		player->position.x++;
	}

}

void Game_State::render_screen() {

	static Entity::Image_Data empty_tile;
	static bool empty_tile_initialized = false;
	if (!empty_tile_initialized) {
		memset(empty_tile.data, '.', sizeof(empty_tile.data));
		empty_tile_initialized = true;
	}

	// clear screen
	for (int i = 0; i < 50; i++) {
		std::cout << std::endl;
	}

	for (int i = 0; i < SCREEN_SIZE.y; i++) {
		std::vector<Entity::Image_Data *> image_row;
		for (int j = 0; j < SCREEN_SIZE.x; j++) {
			Vector2<int> current_pos(j, i);
			std::vector<Entity*> on = get_entity(current_pos);
			image_row.push_back(on.size() == 0 ? &empty_tile : &on.front()->image);
		}	
		for (int j = 0; j < Entity::Image_Data::DATA_Y; j++) {
			for (const Entity::Image_Data* image: image_row) {
				for (int k = 0; k < Entity::Image_Data::DATA_X; k++) {
					char c = image->data[j][k];
					std::cout << (c == ' ' ? '.' : c) << " ";
				}
			}
			std::cout << std::endl;
		}
	}
}

std::vector<Entity*> Game_State::get_entity(const Vector2<int>& pos) {
	std::vector<Entity*> found;
	for (Entity* e: entities) {
		if (e->position == pos) {
			found.push_back(e);
		}
	}
	std::sort(found.begin(), found.end(), [](const Entity* a, const Entity* b) {
		return a->draw_prec > b->draw_prec;
	});
	return found;
}

void Game_State::add_entity(Entity* e) {
	entities.push_back(e);
}

// clear screen
for (int i = 0; i < 50; i++) {
	std::cout << std::endl;
}
