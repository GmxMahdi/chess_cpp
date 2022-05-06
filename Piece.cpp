/* Project : Chess Game Project INF1015
*  File : Piece.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier définie les méthodes contenue dans la classe
*					Piece, elle définie méthodes get communes aux pièces,
*					comme getColor, getPosition et getPossibleMoves ainsi
*					que les méthodes qui détermine si la pièces est à un 
*					adversaire et si un mouvement est possible.
*/

#include "Piece.h"
#include <string>

using namespace std;
using namespace GameModel;

string Piece::getAscii() const
{
	if (_color == Color::WHITE) 
		// Code to add color to the console
		return "\033[30;107;1m"s + getSymbol() + "\033[0m"s;
	else 
		// Code to add color to the console
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
	// If there is no piece or is of opposite color
	return (piece == nullptr || !hasSameColorOfOtherPiece(piece));
}

bool Piece::addMoveIfPossible(Piece* board[8][8], Position move)
{
	// If move is inside the board (fail-safe)
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
