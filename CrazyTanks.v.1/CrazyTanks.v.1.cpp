// CrazyTanks.v.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "Game.h"
#include "Map.h"
#include "Point.h"
#include "Tank.h"
#include "Wall.h"
#include "Bullet.h"
#include "Player.h"
int main()
{
	Map map = Map( Point( 4, 25 ), Point( 0, 50 ) );
	Game game = Game( map );
	game.start();
	//game.finish();
	Point( 25, 0 ).moveCursor();
	system( "pause" );
    return 0;
}

