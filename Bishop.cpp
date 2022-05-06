/* Project : Chess Game Project INF1015
*  File : Bishop.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier définie les méthodes contenue dans la classe
*					Bishop, elle définie une image et un symbole pour la pièce
*					et calcule les mouvements possibles pour la pièces.
*/

#include "Bishop.h"

using namespace std;
using namespace GameModel;
unique_ptr<Piece> Bishop::clone() const
{
	return make_unique<Bishop>(*this);
}

std::string Bishop::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "lt"s : "dt"s);
	return "Chess_b" + colorName + "60.png";
}

char Bishop::getSymbol() const
{
	return 'B';
}

void Bishop::calculatePossibleMoves(Piece* board[8][8])
{
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();


	// Top Right
	{
		int nextRow = row;
		int nextCol = col;
		while (++nextRow < 8 && ++nextCol < 8)
			// If cell is empty or can be captured
			if (!addMoveIfPossible(board, { nextRow, nextCol }))
				break;
			// If cell is empty, we can continue going in that direction
			else if (board[nextRow][nextCol] != nullptr)
				break;
	}

	// Bottom left
	{
		int nextRow = row;
		int nextCol = col;
		while (--nextRow >= 0 && --nextCol >= 0)
			if (!addMoveIfPossible(board, { nextRow, nextCol }))
				break;
			else if (board[nextRow][nextCol] != nullptr)
				break;
	}

	// Top left
	{
		int nextRow = row;
		int nextCol = col;
		while (++nextRow < 8 && --nextCol >= 0)
			if (!addMoveIfPossible(board, { nextRow, nextCol }))
				break;
			else if (board[nextRow][nextCol] != nullptr)
				break;
	}

	{
		int nextRow = row;
		int nextCol = col;
		while (--nextRow >= 0 && ++nextCol < 8)
			if (!addMoveIfPossible(board, { nextRow, nextCol }))
				break;
			else if (board[nextRow][nextCol] != nullptr)
				break;
	}
}
