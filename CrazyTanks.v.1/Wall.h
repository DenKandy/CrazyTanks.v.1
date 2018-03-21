#ifndef WALL_H

#define WALL_H


#include "Point.h"

class Wall {
public:
	char sign;
	Point position;
	int health;
	Wall();
	Wall( Point position, char sign, int health );
	~Wall();
	void destroy();
};
#endif //WALL_H