#ifndef BULLET_H

#define BULLET_H

#include "Point.h"
class Bullet {
public:
	char sign;
	char who;
	Direction dir;
	Point position;

	Bullet();
	Bullet( Point position, char sign, Direction dir, char who );
	~Bullet();
	void move( Bullet& bullet, Point& pos );
private:
	void destroy();
	bool isBlock( Point& pos );
	bool isDestroy( Point& pos );

};
#endif // !BULLET_H
