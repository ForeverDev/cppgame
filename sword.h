#ifndef SWORD_H
#define SWORD_H

#include "entity.h"

class Entity_Sword : public Entity {

	private:

	public:
		int slash;
		int stab;
		int crush;

		Entity_Sword(): Entity_Sword(0, 0) {}
		Entity_Sword(int, int); 
		virtual std::string get_on_top_string();
};

#endif
