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
			}
			break;
		case 80:
			if ( canMove( DOWN ) )
			{
				player.position.Y = position.Y + 1;
			}
			break;
		case 75:
			if ( canMove( LEFT ) )
			{
				player.position.X = position.X - 1;
			}
			break;
		case 77:
			if ( canMove( RIGHT ) )
			{
				player.position.X = position.X + 1;
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
			damage();
		}
		break;
	case DOWN:
		pos = Point( position.Y + 1, position.X );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			damage();
		}
		break;
	case LEFT:
		pos = Point( position.Y, position.X - 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			damage();
		}
		break;
	case RIGHT:
		pos = Point( position.Y, position.X + 1 );
		if ( !isBlock(pos) ) {
			can = true;
		}
		else if ( pos.getChar() == '+' ) {
			can = true;
			damage();
		}
		break;
	}
	return can;
}

void Player::damage()
{
	--health;
	if ( health == 0 )
	{
		position = Point();
	}
}
Bullet Player::shoot()
{
	Bullet bullet;
	int ev = 0;
	if ( _kbhit() != 0 )
	{
		ev = _getch();

		if ( ev == 32 ) 
		{
			bullet = Bullet( position, '*',  dir, '@' );
			bullet.move();
		}
	}

	return bullet;
}
bool Player::isBlock(Point pos)
{
	return ( pos.getChar() == '-' || pos.getChar() == '%' || pos.getChar() == '|' || pos.getChar() == '#');
}
