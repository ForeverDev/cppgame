#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <array>
#include "entity.h"
#include "player.h"

class Game_State {

	private:
		std::vector<Entity*> entities;
		Vector2<int> SCREEN_SIZE = Vector2<int>(8, 8);
		Entity_Player* player;
		std::vector<Entity*> sitting_on;
		std::array<std::string, 5> bottom_rows;

		void render_screen();
		void add_entity(Entity*);
		void remove_entity(const Entity*);
		std::vector<Entity*> get_entities(const Vector2<int>&);

	public:
		Game_State();
		void main_loop();
		void move_player(const std::string&);

};

#endif
