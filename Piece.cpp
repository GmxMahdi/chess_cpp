#include "Piece.h"
#include <string>

using namespace std;

string Piece::getAscii() const
{
	if (_color == Color::WHITE) 
		return "\033[30;107;1m"s + getSymbol() + "\033[0m"s;
	else 
		return "\033[44;97;1m"s + getSymbol() + "\033[0m"s;
}

Color Piece::getColor() const
{
	return _color;
}

Position Piece::getPosition() const
{
	return _position;
}

std::unordered_set<Position> Piece::getPossibleMoves() const
{
	return _moves;
}

bool Piece::hasSameColorOfOtherPiece(Piece* piece)
{
	return (this->_color == piece->_color);
}

bool Piece::canStepOnPiece(Piece* piece)
{
	return (piece == nullptr || !hasSameColorOfOtherPiece(piece));
}

bool Piece::addMoveIfPossible(Piece* board[8][8], Position move)
{
	if (move.getRow() < 0 || move.getRow() > 7 ||
		move.getCol() < 0 || move.getCol() > 7)
		return false;

	if (canStepOnPiece(board[move.getRow()][move.getCol()]))
	{
		_moves.insert(move);
		return true;
	}

	return false;
}
