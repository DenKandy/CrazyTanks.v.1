#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include "Point.h"
Point::Point()
{
	X = 0;
	Y = 0;
}
Point::Point( int y, int x ) : X( x ), Y( y )
{
}

Point::~Point()
{
}
bool Point::operator == ( const Point &points ) {
	return ( X == points.X && Y == points.Y );
}
char Point::getChar() {
	char c = '\0';
	CONSOLE_SCREEN_BUFFER_INFO con;
	HANDLE hcon = GetStdHandle( STD_OUTPUT_HANDLE );
	moveCursor();
	if ( hcon != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo( hcon, &con ) )
	{
		DWORD read = 0;
		if ( !ReadConsoleOutputCharacterA( hcon, &c, 1, con.dwCursorPosition, &read ) || read != 1 ) {
			c = '\0';
		}

	}
	return c;
}
void Point::moveCursor() {
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void Point::setChar( char sign ) {
	moveCursor();
	std::cout << sign;
}