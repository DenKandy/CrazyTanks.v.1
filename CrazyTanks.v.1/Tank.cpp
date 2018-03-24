#include "stdafx.h"
#include "Player.h"
#include "Tank.h"
#include "Point.h"
#include "Bullet.h"

#include <cstdlib>
#include <windows.h>
#include <time.h>

Tank::Tank():Player(){}
Tank::Tank( Point position, char sign, int health ) :Player(position, sign, health) {}
Tank::~Tank() {

}
void Tank::action( Tank & tank, Bullet & bullet )
{
	auto last_pos = tank.position;
	tank.move( tank );
	if ( !(last_pos == tank.position) )
	{
		tank.shoot( bullet, ENEMY );
	}
}
void Tank::move(Tank& tank) 
{
	if ( position == Point() )
	{
		return;
	}
	int times = 0;
	do
	{
		dir = static_cast< Direction >( rand() % 4 );
	} while ( !canMove( dir ) );
	switch ( dir )
	{
	case UP:
		tank.position.Y = position.Y - 1;
		dir = UP;
		break;
	case DOWN:
		tank.position.Y = position.Y + 1;
		dir = DOWN;
		break;
	case LEFT:
		tank.position.X = position.X - 1;
		dir = LEFT;
		break;
	case RIGHT:
		tank.position.X = position.X + 1;
		dir = RIGHT;
		break;
	case STOP:
		dir = STOP;
	}
}

