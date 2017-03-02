#ifndef GAME_H
#define GAME_H

#include <vector>
#include "entity.h"
#include "player.h"

class Game_State {

	private:
		std::vector<Entity*> entities;
		Vector2<int> SCREEN_SIZE = Vector2<int>(8, 8);
		Player* player;

		void render_screen();
		void add_entity(Entity*);
		std::vector<Entity*> get_entity(const Vector2<int>&);

	public:
		Game_State();
		void main_loop();

};

#endif
