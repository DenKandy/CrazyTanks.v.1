#ifndef BULLET_H

#define BULLET_H

#include "Point.h"

class Bullet {
public:
	char sign;
	char type;
	Direction dir;
	Point position;

	Bullet();
	Bullet( Point position, char sign, Direction dir, char type );
	~Bullet();
	bool isBlock();
	void move();
	void destroy();

};
#endif // !BULLET_H
