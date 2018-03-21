#ifndef GAME_H

#define GAME_H

#include "Map.h"
#include <time.h>

class Game {
public:
	int score;
	clock_t timeGame;
	Map map;

	Game( Map map );
	~Game();
	void start();
	void finish();
private:
	void showScoreboard();
};
#endif // !GAME_H