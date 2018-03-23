#ifndef POINT_H

#define POINT_H


enum Direction {UP, DOWN, LEFT, RIGHT, STOP};
const char PLAYER = '@';
const char ENEMY = '%';
const char GOLD = '~';
const char WALL = '#';
const char BULLET = '*';
const char UP_DOWN_BORDER = '-';
const char LEFT_RIGHT_BORDER = '|';
const char FIELD = ' ';
const char END_STR = '\0';
const int START_HEALTH = 3;
const int COUNT_TANKS = 3;
const int COUNT_WALL_POINT = 50;
const int POS_HEALTH = 2;
const int POS_CHANGE_HEALTH = 10;
const int POS_CHANGE_SCORE = 20;
const int POS_CHANGE_TIME = 30;
const int POS_SCORE = 13;
const int POS_TIME = 23;
const int POS_HELP = 53;
const int SECOND_IN_HOUR = 3600;
const int SECOND_IN_MINUTE = 60;
const int GO_UP = 72;
const int GO_DOWN = 80;
const int GO_LEFT = 75;
const int GO_RIGHT = 77;
const int SHOOT = 32;
const int EXIT = 27;
const int SLEEP_TANK = 300;
const int SLEEP_BULLET = 20;
const int MAX_HEIGHT = 25;
const int MIN_HEIGHT = 4;
const int MAX_WIDHT = 50;
const int MIN_WIDTH = 0;

class Point
{
public:
	int X;
	int Y;

	Point();
	Point(int y, int x);
	~Point();
	bool operator == ( const Point &point );
	void setChar(char sign);
	char getChar();
	void moveCursor();
};
#endif // !POINT_H
