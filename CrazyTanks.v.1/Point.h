#ifndef POINT_H

#define POINT_H


enum Direction {UP, DOWN, LEFT, RIGHT, STOP};
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
