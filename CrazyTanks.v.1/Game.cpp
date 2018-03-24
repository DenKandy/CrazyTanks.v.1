#include "stdafx.h"
#include "Game.h"
#include "Point.h"
#include "Map.h"
#include "Bullet.h"

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <mutex>

#include <conio.h>

using namespace std;
Game::Game()
{
	map = Map( Point( MIN_HEIGHT, MAX_HEIGHT ), Point( MIN_WIDTH, MAX_WIDHT ) );
	timeGame = clock();
	goon = true;
}

Game::~Game()
{
}

void Game::start()
{
	//draw scoreboard
	showScoreboard();
	//draw map
	srand( time( 0 ) );
	map.draw();
}

void Game::finish()
{
	system( "cls" );
	Point( map.height.X / 2  , map.width.X / 2 ).moveCursor();
	if ( map.player.health != 0 && ( map.position_gold == Point() ) ) {
		cout << "Victory !!!";
	}
	else {
		cout << "Game over !!!";
	}
	system( "pause" );
}

void Game::control_player_tank()
{
		auto last_pos_player = map.player.position;
		Bullet bullet;
		
		goon = map.player.tryAction( map.player, bullet );
		if ( !( bullet.position == Point() ) )
		{
			map.bullets.push_back( bullet );
		}
		if ( !( map.player.position == last_pos_player ) )
		{
			map.update( map.player.position, last_pos_player, map.player.sign );
		}
		
}

void Game::control_enemy_tank()
{		
	Bullet bullet; int count_kill_tanks = 0;
	for ( size_t i = 0; i < map.tanks.size(); i++ )
	{
		if ( map.tanks[i].position == Point() )
		{
			continue;
			count_kill_tanks++;
		}
		auto last_pos_tank = map.tanks[i].position;

		map.tanks[i].action( map.tanks[i], bullet );
		map.bullets.push_back( bullet );
		map.update( map.tanks[i].position, last_pos_tank, map.tanks[i].sign );


	}	
		updateScoreboard();
		
		if ( count_kill_tanks == COUNT_TANKS )
		{
			goon = false;
		}
		else 
		{
			count_kill_tanks = 0;
		}
}
void Game::control_fly_bullet()
{
	for ( size_t i = 0; i < map.bullets.size(); i++ )
	{
		if ( map.bullets[i].position == Point() )
		{
			continue;
		}
		auto last_pos_tank = map.bullets[i].position;
		Point pos = Point();
		map.bullets[i].move( map.bullets[i], pos );
		if ( !( pos == Point() ) )
		{
			if ( pos == map.player.position ) {
				goon = map.player.tryDamage();
			}
			else if ( pos == map.position_gold ) {
				goon = false;
			}
			for ( size_t i = 0; i < map.walls.size(); i++ )
			{
				if ( pos == map.walls[i].position ) {

					if ( !map.walls[i].tryDestroy( map.walls[i] ) )
					{
						pos.setChar( ' ' );
					}
					break;
				}
			}
			for ( size_t i = 0; i < map.tanks.size(); i++ )
			{
				if ( pos == map.tanks[i].position ) {

					map.tanks[i].position = Point();
					pos.setChar( FIELD );

					score += 10;
				}
			}
		}
		map.update( map.bullets[i].position, last_pos_tank, map.bullets[i].sign );
	}
}
void Game::showScoreboard()
{
	auto points = Point( POS_HEALTH, POS_HEALTH );
	points.moveCursor();
	cout << "health: " << map.player.health;
	points.X = POS_SCORE;
	points.moveCursor();
	cout << "score: " << score;
	points.X = POS_TIME;
	points.moveCursor();
	cout << "time: ";
	points.X = POS_HELP;
	points.moveCursor();
	cout << "- @ tank of player";
	//turn new line
	points.Y = 3;
	points.moveCursor();
	cout << "- % tank of enemy";
	//turn new line
	points.Y = 4;
	points.moveCursor();
	cout << "- * bullets";
	//turn new line
	points.Y = 5;
	points.moveCursor();
	cout << "- ~ gold";
}

void Game::updateScoreboard()
{
	seconds = ( ( clock() - timeGame ) / CLOCKS_PER_SEC );
	int hour = seconds / SECOND_IN_HOUR;
	minutes = ( seconds - ( hour * SECOND_IN_HOUR ) ) / SECOND_IN_MINUTE;
	seconds = seconds - ( hour * SECOND_IN_HOUR ) - ( minutes * SECOND_IN_MINUTE );
	auto points = Point( POS_HEALTH, POS_CHANGE_HEALTH );
	points.moveCursor();
	cout << map.player.health;
	points.X = POS_CHANGE_SCORE;
	points.moveCursor();
	cout << score;
	points.X = POS_CHANGE_TIME;
	points.moveCursor();
	cout << minutes << ":" << seconds << " ";
}
