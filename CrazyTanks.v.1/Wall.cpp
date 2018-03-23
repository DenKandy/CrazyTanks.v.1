#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
	position = Point( 0, 0 );
}

Wall::Wall( Point position, char sign, int health ):position(position), sign(sign), health(health)
{
}

Wall::~Wall()
{
}

bool Wall::tryDestroy( Wall&  wall )
{
	wall.health = wall.health - 1;
	if ( wall.health == 0 )
	{
		position = Point();
		return false;
	}
	return true;
}



