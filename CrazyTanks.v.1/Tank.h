#ifndef TANK_H

#define TANK_H

#include "Point.h"
#include "Bullet.h"
#include "Player.h"


class Tank: public Player {
public:
	Tank();
	Tank( Point position, char sign, int health );
	~Tank();
	void action( Tank& tank, Bullet& bullet );
private:
	void move( Tank& tank );
};
#endif // TANK_H