#ifndef TANK_H

#define TANK_H

#include "Point.h"

class Tank {
public:
	char sign;
	Direction dir;
	Point position;
	Tank();
	Tank( Point position, char sign );
	~Tank();
	void move();
	void shoot();
	void destroy();
};
#endif // TANK_H