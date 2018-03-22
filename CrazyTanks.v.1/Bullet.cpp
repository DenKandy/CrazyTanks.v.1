#include "stdafx.h"
#include "Point.h"
#include "Bullet.h"

Bullet::Bullet()
{
	position = Point();
}

Bullet::Bullet( Point position, char sign, Direction dir, char type ) : position( position ), sign( sign ), dir( dir ), type( type )
{

}
Bullet::~Bullet(){}
bool Bullet::isBlock()
{
	return ( position.getChar() == '-' || position.getChar() == type || position.getChar() == '|' );
}
void Bullet::move() 
{
}
void Bullet::destroy() 
{

}