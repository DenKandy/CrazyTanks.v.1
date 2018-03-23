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
		case 72:
			if ( canMove( UP ) )
			{
				player.position.Y = position.Y - 1;
				dir = UP;
			}
			break;
		case 80:
			if ( canMove( DOWN ) )
			{
				player.position.Y = position.Y + 1;
				dir = DOWN;
			}
			break;
		case 75:
			if ( canMove( LEFT ) )
			{
				player.position.X = position.X - 1;
				dir = LEFT;
			}
			break;
		case 77:
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

		if ( ev == 32 ) 
		{
			bullet.position = position;
			switch ( dir )
			{
			case UP:
				bullet.position.Y = position.Y - 1;
				break;
			case DOWN:
				bullet.position.Y = position.Y + 1;
				break;
			case LEFT:
				bullet.position.X = position.X - 1;
				break;
			case RIGHT:
				bullet.position.X = position.X + 1;
				break;
			}
			bullet = Bullet( bullet.position, '*',  dir, '@' );

		}
	}
}
bool Player::isBlock(Point pos)
{
	return ( pos.getChar() == '-' || pos.getChar() == '%' || pos.getChar() == '|' || pos.getChar() == '#');
}
