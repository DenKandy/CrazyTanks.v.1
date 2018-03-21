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

void Wall::destroy()
{
}

