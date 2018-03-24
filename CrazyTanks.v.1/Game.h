#ifndef GAME_H

#define GAME_H

#include "Map.h"

#include <time.h>
#include <mutex>

class Game {
public:
	int score, minutes, seconds;
	bool goon;
	clock_t timeGame;
	Map map;

	Game();
	~Game();
	void start();
	void finish();
	void control_player_tank();
	void control_enemy_tank();
	void control_fly_bullet();
private:
	void showScoreboard();
	void updateScoreboard();
};
#endif // !GAME_H