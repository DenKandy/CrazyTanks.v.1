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
	std::vector<Tank> tanks;
	Player player;
	std::vector<Bullet> bullets;
	std::vector<Wall> walls;

	Map( Point height, Point width );
	~Map();
	void draw();
	void update( Point& player, Point last_pos, char sign );


private:
};

#endif // MAP_H