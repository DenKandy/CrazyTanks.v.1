#ifndef MAP_H

#define MAP_H

#include "Point.h"
#include "Player.h"
#include "Bullet.h"
#include "Tank.h"
#include "Wall.h"

#include <vector>
#include <list>

class Map
{
public:
	const char gold = '~';
	const char border = '=';
	Point position_gold;
	Point height;
	Point width;
	std::list<Tank> tanks;
	Player player;
	std::list<Bullet> bullet_tank;
	std::list<Bullet> bullet_player;
	std::list<Wall> walls;

	Map( Point height, Point width );
	~Map();
	void draw();
	void update();

private:
};

#endif // MAP_H