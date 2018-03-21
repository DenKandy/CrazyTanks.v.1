#ifndef BULLET_H

#define BULLET_H

#include "Point.h"

class Bullet {
public:
	char sign;
	Direction dir;
	Point position;

	Bullet();
	Bullet( Point position, char sign, Direction dir );
	~Bullet();
	
	void move();
	void destroy();

};
#endif // !BULLET_H
