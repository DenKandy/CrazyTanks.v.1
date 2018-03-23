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
	~Player();
	void move( Player& player );
	bool canMove( Direction dir );
	bool tryDamage();
	void shoot( Bullet& bullet );
private:
	bool isBlock(Point pos);

};
#endif //PLAYER_H


