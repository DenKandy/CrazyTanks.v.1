#ifndef PLAYER_H

#define PLAYER_H

#include "Point.h"

class Player
{
public:
	char sign;
	Point position;
	Direction dir;
	int health;

	Player();
	Player(Point position, char sign, int health);
	~Player();
	void move();
	void destroy();

};
#endif //PLAYER_H


