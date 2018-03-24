#ifndef PLAYER_H

#define PLAYER_H

#include "Point.h"
#include "Bullet.h"

class Player
{
public:
	char sign;
	Point position;
	Direction dir;
	int health;

	Player();
	Player( Point position, char sign, int health );
	virtual ~Player();
	bool tryAction( Player& player, Bullet& bullet );
	bool tryDamage();
private:
	void move( Player& player, Direction dir );
	
protected:
	bool isBlock( Point pos );
	bool canMove( Direction dir );
	void shoot( Bullet& bullet, const char who );
};
#endif //PLAYER_H


