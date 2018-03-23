#include "stdafx.h"
#include "Point.h"
#include "Bullet.h"

#include <vector>

Bullet::Bullet()
{
	position = Point();
}

Bullet::Bullet( Point position, char sign, Direction dir, char who ) : position( position ), sign( sign ), dir( dir ), who( who )
{

}
Bullet::~Bullet(){}
bool Bullet::isBlock( Point& pos )
{
	return ( pos.getChar() == '-' || pos.getChar() == who || pos.getChar() == '|');
}
bool Bullet::isDestroy( Point& pos )
{
	return ( pos.getChar() == '#' || pos.getChar() == '@' || pos.getChar() == '~' );
}
void Bullet::move( Bullet& bullet, Point& pos )
{
	auto temp = position;
	switch ( dir )
		{
		case UP:
				position.Y = position.Y - 1;				
			break;
		case DOWN:
				position.Y = position.Y + 1;
			break;
		case LEFT:
			    position.X = position.X - 1;
			break;
		case RIGHT:
				position.X = position.X + 1;
			break;
		}
	if ( isBlock( position ) )
	{
		position = temp;
		destroy();
	}
	else if ( isDestroy( position ) )
	{
		
		pos = position;
		position = temp;
		destroy();
	}
}
void Bullet::destroy() 
{
	position = Point();
}