#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
	
	private:

	public:
		Player(): Player(0, 0) {}
		Player(int, int); 
		
};

#endif
