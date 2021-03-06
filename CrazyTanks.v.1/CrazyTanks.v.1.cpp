// CrazyTanks.v.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include "Game.h"
#include "Map.h"

#include <Windows.h>
#include <thread>
#include <mutex>
#include <conio.h>

using namespace std;
void thread_one( Game& game, mutex& mtx );
void thread_two( Game& game, mutex& mtx );
void thread_three( Game& game, mutex& mtx );

int main()
{
	
	Game game = Game();
		game.start();

		mutex mtx;
		thread t1( thread_one, ref( game ), ref( mtx ) );
		thread t2( thread_two, ref( game ), ref( mtx ) );
		thread t3( thread_three, ref( game ), ref( mtx ) );
		thread_one( game, mtx );
		thread_two( game, mtx );
		thread_three( game, mtx );
		t1.detach();
		t2.detach();
		t3.detach();
	
	
     return 0;
}
void thread_one( Game& game, mutex& mtx ) {
	
	while ( game.goon )
	{
		mtx.lock();
		if ( !game.goon )
		{
			game.finish();
		}
		mtx.unlock();
		Sleep( SLEEP_PLAYER );
	}
	
}
void thread_two( Game& game, mutex& mtx ) {
	
	while ( game.goon )
	{
		mtx.lock();

		game.control_player_tank();

		game.control_fly_bullet();

		mtx.unlock();
		Sleep( SLEEP_PLAYER );
	}
	//thread_one( true, mtx );

}
void thread_three( Game& game, mutex& mtx ) {
	
	while ( game.goon )
	{
		mtx.lock();
		game.control_enemy_tank();
		
		mtx.unlock();
		Sleep( SLEEP_TANK );
	}
	
}

