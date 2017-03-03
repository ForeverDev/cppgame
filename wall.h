#ifndef WALL_H
#define WALL_H

#include "entity.h"

class Entity_Wall : public Entity {
	
	private:

	public:
		Entity_Wall(): Entity_Wall(0, 0) {}
		Entity_Wall(int, int); 
		virtual std::string get_on_top_string();
		
};

#endif
