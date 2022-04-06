#include "Position.h"

Position::Position() : _x(0), _y(0)
{
}

Position::Position(int x, int y): _x(x), _y(y)
{
}

Position::Position(const Position& position): _x(position._x), _y(position._y)
{
}

int Position::getX() const
{
	return _x;
}

int Position::getY() const
{
	return _y;
}

void Position::setX(int x)
{
	_x = x;
}

void Position::setY(int y)
{
	_y = y;
}
