#include "stdafx.h"
#include "Point.h"
#include "Player.h"


Player::Player()
{
	position = Point();
}

Player::Player( Point position, char sign, int health ) : position( position ), sign( sign ), health( health )
{
}

Player::~Player()
{
}

void Player::move()
{
}

void Player::destroy()
{
}