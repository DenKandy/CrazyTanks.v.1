#ifndef TANK_H

#define TANK_H

#include "Point.h"
#include "Bullet.h"

class Tank {
public:
	char sign;
	Direction dir;
	Point position;
	Tank();
	Tank( Point position, char sign );
	~Tank();
	void move( Tank& tank );
	void shoot( Bullet& bullet );
	void destroy();
private:
	bool isBlock( Point pos );
	bool canMove( Direction dir );
};
#endif // TANK_H