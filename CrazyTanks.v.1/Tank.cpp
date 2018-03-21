#include "stdafx.h"
#include "Tank.h"
#include "Point.h"
Tank::Tank()
{
	position = Point();
}
Tank::Tank( Point position, char sign ) : position( position ), sign(sign) {

}
Tank::~Tank() {

}
void Tank::move() {

}
void Tank::shoot() {

}
void Tank::destroy() {

}