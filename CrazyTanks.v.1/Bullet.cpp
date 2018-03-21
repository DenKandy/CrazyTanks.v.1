#include "stdafx.h"
#include "Point.h"
#include "Bullet.h"

Bullet::Bullet()
{
	position = Point();
}

Bullet::Bullet( Point position, char sign, Direction dir ) : position( position ), sign( sign ), dir( dir ) {

}
Bullet::~Bullet(){}
void Bullet::move() {

}
void Bullet::destroy() {

}