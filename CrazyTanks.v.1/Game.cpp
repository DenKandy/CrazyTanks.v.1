#include "stdafx.h"
#include <iostream>

#include "Game.h"
#include "Point.h"
#include "Map.h"

using namespace std;
Game::Game( Map map ) : map( map )
{
	timeGame = clock();
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
}

void Game::showScoreboard()
{
	auto points = Point( 2, 2 );
	points.moveCursor();
	cout << "health: " << map.player.health;
	points.X = 13;
	points.moveCursor();
	cout << "score: " << score;
	points.X = 23;
	points.moveCursor();
	cout << "time: " << ( clock() - timeGame ) / CLOCKS_PER_SEC << "  s. ";
}
