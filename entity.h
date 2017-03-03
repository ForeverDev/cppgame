#ifndef ENTITY_H
#define ENTITY_H

#include "vector2.h"
#include "assert.h"
#include "string.h"
#include <string>

class Entity {

	private:

	public:
		Entity(): position(0, 0) { }
		Entity(int x, int y): position(x, y) { }
		virtual ~Entity() {}
		virtual std::string get_on_top_string() = 0;

		struct Image_Data {
			Image_Data() {
				memset(data, 0, DATA_X * DATA_Y);
			}

			Image_Data(const std::string& str) {
				assert(str.length() == DATA_X * DATA_Y);
				memcpy(data, str.c_str(), DATA_X * DATA_Y);
			}

			static const int DATA_X = 5;
			static const int DATA_Y = 5;
			char data[DATA_X][DATA_Y];
		};
		
		int draw_prec = 0;	
		Image_Data image;
		Vector2<int> position;
	

};

#endif
