#include <algorithm>
#include "string.h"
#include "wall.h"
#include "sword.h"
#include "game.h"

Game_State::Game_State() {
	player = new Entity_Player(1, 0);
	add_entity(player);

	add_entity(new Entity_Wall(2, 0));
	add_entity(new Entity_Wall(2, 1));
	add_entity(new Entity_Sword(3, 0));
}

void Game_State::main_loop() {

	std::string move;

	while (true) {
		render_screen();
		std::cin >> move;
		
		// convert input to lowercase
		std::transform(move.begin(), move.end(), move.begin(), [](char c) -> char {
			return std::tolower(c);	
		});

		if (move == "w" || move == "a" || move == "s" || move == "d") {
			move_player(move);
		}

	}

}

void Game_State::move_player(const std::string& movement) {
	// constrain helper
	static auto constrain = [](int value, int low, int high) -> int {
		return (value < low) ? low : (value > high) ? high : value;
	};

	Vector2<int> original_position = player->position;
	int dx = (movement == "a") ? -1 : (movement == "d") ? 1 : 0;
	int dy = (movement == "w") ? -1 : (movement == "s") ? 1 : 0;

	player->position.x = constrain(player->position.x + dx, 0, SCREEN_SIZE.x - 1);
	player->position.y = constrain(player->position.y + dy, 0, SCREEN_SIZE.y - 1);

	std::vector<Entity*> entities = get_entities(player->position);

	// reset all bottom rows
	for (int i = 0; i < bottom_rows.size(); i++) {
		bottom_rows[i] = "";
	}
	
	// if there is more than one entity on the tile, there is a collision!
	if (entities.size() > 1) {
		// entities are sorted by draw_prec from greatest to least... 
		// player is guarenteed to be entities[0], so the entity
		// that was stepped on is in entities[1]
		Entity* hit = entities[1];
		assert(hit != player);
		
		// if it's a wall, reset player to where it was
		if (dynamic_cast<Entity_Wall *>(hit)) {
			player->position = original_position;	
		} else if (Entity_Sword* sword = dynamic_cast<Entity_Sword *>(hit)) {
			bottom_rows[0] = sword->get_on_top_string();
		}
	}
	
	sitting_on = std::move(entities);
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

	auto draw_row_border = [&]() {
		for (int k = 0; k < Entity::Image_Data::DATA_X*SCREEN_SIZE.x + SCREEN_SIZE.x; k++) {
			std::cout << "--";
		}
		std::cout << std::endl;
	};
	
	draw_row_border();

	for (int i = 0; i < SCREEN_SIZE.y; i++) {
		std::vector<Entity::Image_Data *> image_row;
		for (int j = 0; j < SCREEN_SIZE.x; j++) {
			Vector2<int> current_pos(j, i);
			std::vector<Entity*> on = get_entities(current_pos);
			image_row.push_back(on.size() == 0 ? &empty_tile : &on.front()->image);
		}	
		for (int j = 0; j < Entity::Image_Data::DATA_Y; j++) {
			for (int k = 0; k < image_row.size(); k++) {
				Entity::Image_Data* image = image_row[k];
				std::cout << "| ";
				for (int m = 0; m < Entity::Image_Data::DATA_X; m++) {
					std::cout << (image->data[j][m] == ' ' ? '.' : image->data[j][m]) << " ";
				}
				if (k == image_row.size() - 1) {
					std::cout << "| ";
				}
			}
			std::cout << std::endl;
		}
		draw_row_border();
	}

	for (int i = 0; i < bottom_rows.size(); i++) {
		if (bottom_rows[i] != "") {
			std::cout << i << ". " << bottom_rows[i];
		}
		std::cout << std::endl;
	}
}

std::vector<Entity*> Game_State::get_entities(const Vector2<int>& pos) {
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

void Game_State::remove_entity(const Entity* e) {
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i] == e) {
			entities.erase(entities.begin() + i);
			return;
		}
	}
	assert(0);
}
