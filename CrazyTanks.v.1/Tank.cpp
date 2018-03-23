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
	int times = 0;
	do
	{
		dir = static_cast< Direction >( rand() % 4 );
		times++;
		if ( times > 3 ) {
			times = 0;
			return;
		}

	} while ( !canMove( dir ) );
	switch ( dir )
	{
	case UP:
		tank.position.Y = tank.position.Y - 1;
		dir = UP;
		break;
	case DOWN:
		tank.position.Y = tank.position.Y + 1;
		dir = DOWN;
		break;
	case LEFT:
		tank.position.X = tank.position.X - 1;
		dir = LEFT;
		break;
	case RIGHT:
		tank.position.X = tank.position.X + 1;
		dir = RIGHT;
		break;
	}
}
void Tank::shoot( Bullet& bullet ) 
{
	bullet.position = position;
	bullet.dir = dir;
	bullet.move( bullet, position );

	bullet = Bullet( bullet.position, '*', dir, '%' );
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
		else if ( pos.getChar() == '*' ) {
			can = true;
			destroy();
		}
		break;
	case DOWN:
		pos = Point( position.Y + 1, position.X );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == '*' ) {
			can = true;
			destroy();
		}
		break;
	case LEFT:
		pos = Point( position.Y, position.X - 1 );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == '*' ) {
			can = true;
			destroy();
		}
		break;
	case RIGHT:
		pos = Point( position.Y, position.X + 1 );
		if ( !isBlock( pos ) ) {
			can = true;
		}
		else if ( pos.getChar() == '*' ) {
			can = true;
			destroy();
		}
		break;
	}
	return can;
}
bool Tank::isBlock( Point pos )
{
	return ( pos.getChar() == '-' || pos.getChar() == '%' || pos.getChar() == '@' || pos.getChar() == '|' || pos.getChar() == '#' );
}