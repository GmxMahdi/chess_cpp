#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);
	Position(const Position& position);

	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
private:
	int _x;
	int _y;
};