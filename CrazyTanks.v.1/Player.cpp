#include "stdafx.h"
#include "Point.h"
#include "Player.h"
#include "Bullet.h"


#include <conio.h>


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

bool Player::tryAction( Player& player, Bullet& bullet )
{
	int ev = 0;
	if ( _kbhit() != 0 )
	{
		ev = _getch();
		switch ( ev )
		{
		case GO_UP:
			move( player, UP );
			break;
		case GO_DOWN:
			move( player, DOWN );
			break;
		case GO_LEFT:
			move( player, LEFT );
				break;
		case GO_RIGHT:
			move( player, RIGHT );
			break;
		case SHOOT:
			shoot( bullet, PLAYER );
			break;
		case EXIT:
			return false;
			break;
		}
	}
	return true;
}

void Player::move( Player& player, Direction dir )
{
		switch ( dir )
		{
		case UP:
			if ( canMove( dir ) )
			{
				player.position.Y = position.Y - 1;
			}
			break;
		case DOWN:
			if ( canMove( dir ) )
			{
				player.position.Y = position.Y + 1;
			}
			break;
		case LEFT:
			if ( canMove( dir ) )
			{
				player.position.X = position.X - 1;
			}
			break;
		case RIGHT:
			if ( canMove( dir ) )
			{
				player.position.X = position.X + 1;
			}
			break;
		}
		this->dir = dir;
}

bool Player::canMove( Direction dir )
{
	bool can = false; Point pos;
	switch ( dir )
	{
	case UP:
		pos = Point( position.Y - 1, position.X );
		if ( !isBlock(pos) ) {
			can = true;
		}
		break;
	case DOWN:
		pos = Point( position.Y + 1, position.X );
		if ( !isBlock(pos) ) {
			can = true;
		}
		break;
	case LEFT:
		pos = Point( position.Y, position.X - 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		break;
	case RIGHT:
		pos = Point( position.Y, position.X + 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		break;
	}
	return can;
}

bool Player::tryDamage()
{
	health = health - 1;
	if ( health == 0 )
	{
		position = Point();
		return false;
	}
	return true;
}
void Player::shoot( Bullet& bullet, const char who )
{
		bullet = Bullet( position, BULLET, dir, who );
		bullet.move( bullet, bullet.position );
}
bool Player::isBlock(Point pos)
{
	return ( pos.getChar() == UP_DOWN_BORDER || pos.getChar() == ENEMY || pos.getChar() == PLAYER || pos.getChar() == LEFT_RIGHT_BORDER || pos.getChar() == WALL );
}
