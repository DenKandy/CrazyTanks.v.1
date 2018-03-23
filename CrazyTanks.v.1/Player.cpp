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

void Player::move( Player& player )
{
	int ev = 0;
	if ( _kbhit() != 0 )
	{
		ev = _getch();
		switch ( ev )
		{
		case GO_UP:
			if ( canMove( UP ) )
			{
				player.position.Y = position.Y - 1;
				dir = UP;
			}
			break;
		case GO_DOWN:
			if ( canMove( DOWN ) )
			{
				player.position.Y = position.Y + 1;
				dir = DOWN;
			}
			break;
		case GO_LEFT:
			if ( canMove( LEFT ) )
			{
				player.position.X = position.X - 1;
				dir = LEFT;
			}
			break;
		case GO_RIGHT:
			if ( canMove( RIGHT ) )
			{
				player.position.X = position.X + 1;
				dir = RIGHT;
			}
			break;
		}
	}
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
		else if ( pos.getChar() == '+' ) {
			can = true;
			tryDamage();
		}
		break;
	case DOWN:
		pos = Point( position.Y + 1, position.X );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			tryDamage();
		}
		break;
	case LEFT:
		pos = Point( position.Y, position.X - 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			tryDamage();
		}
		break;
	case RIGHT:
		pos = Point( position.Y, position.X + 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			tryDamage();
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
void Player::shoot( Bullet& bullet )
{
	int ev = 0;
	if ( _kbhit() != 0 )
	{
		ev = _getch();

		if ( ev == SHOOT ) 
		{
			bullet = Bullet( position, BULLET, dir, PLAYER );
			bullet.move( bullet, bullet.position );
			//bullet = Bullet( bullet.position, '*',  dir, '@' );

		}
	}
}
bool Player::isBlock(Point pos)
{
	return ( pos.getChar() == '-' || pos.getChar() == '%' || pos.getChar() == '|' || pos.getChar() == '#');
}
