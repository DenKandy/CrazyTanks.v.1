#include "stdafx.h"
#include "Tank.h"
#include "Point.h"
#include "Bullet.h"

#include <cstdlib>
#include <windows.h>
#include <time.h>


Tank::Tank()
{
	position = Point();
}
Tank::Tank( Point position, char sign ) : position( position ), sign(sign) {

}
Tank::~Tank() {

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
void Tank::shoot( Bullet& bullet ) 
{
	bullet = Bullet( position, BULLET, dir, ENEMY );
	bullet.move( bullet, bullet.position );
}
void Tank::destroy() {

}
bool Tank::canMove( Direction dir )
{
	bool can = false; Point pos;
	switch ( dir )
	{
	case UP:
		pos = Point( position.Y - 1, position.X );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == BULLET ) {
			can = true;
			destroy();
		}
		break;
	case DOWN:
		pos = Point( position.Y + 1, position.X );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == BULLET ) {
			can = true;
			destroy();
		}
		break;
	case LEFT:
		pos = Point( position.Y, position.X - 1 );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == BULLET ) {
			can = true;
			destroy();
		}
		break;
	case RIGHT:
		pos = Point( position.Y, position.X + 1 );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == BULLET ) {
			can = true;
			destroy();
		}
		break;
	}
	return can;
}
bool Tank::isBlock( Point pos )
{
	return ( pos.getChar() == UP_DOWN_BORDER || pos.getChar() == ENEMY || pos.getChar() == PLAYER || pos.getChar() == LEFT_RIGHT_BORDER || pos.getChar() == WALL );
}