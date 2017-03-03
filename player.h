#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Entity_Player : public Entity {
	
	private:

	public:
		Entity_Player(): Entity_Player(0, 0) {}
		Entity_Player(int, int); 
		virtual std::string get_on_top_string();
		
};

#endif
