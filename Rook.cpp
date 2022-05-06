/* Project : Chess Game Project INF1015
*  File : Rook.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier définie les méthodes contenue dans la classe
*					Rook, elle définie une image et un symbole pour la pièce
*					et calcule les mouvements possibles pour la pièces.					
*/

#include "Rook.h"

using namespace std;
using namespace GameModel;

unique_ptr<Piece> Rook::clone() const
{
	return make_unique<Rook>(*this);
}

std::string Rook::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "lt"s : "dt"s);
	return "Chess_r" + colorName + "60.png";
}

char Rook::getSymbol() const
{
	return 'R';
}

void Rook::calculatePossibleMoves(Piece* board[8][8])
{
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();


	// Top
	{
		int nextRow = row;
		while (--nextRow >= 0)
			// If cell is empty or can be captured
			if (!addMoveIfPossible(board, { nextRow, col }))
				break;
			// If cell is empty, we can continue going in that direction
			else if (board[nextRow][col] != nullptr)
				break;
	}

	// Bottom
	{
		int nextRow = row;
		while (++nextRow < 8)
			if (!addMoveIfPossible(board, { nextRow, col }))
				break;
			else if (board[nextRow][col] != nullptr)
				break;
	}

	// Left
	{
		int nextCol = col;
		while (--nextCol >= 0)
			if (!addMoveIfPossible(board, { row, nextCol }))
				break;
			else if (board[row][nextCol] != nullptr)
				break;
	}

	// Right
	{
		int nextCol = col;
		while (++nextCol < 8)
			if (!addMoveIfPossible(board, { row, nextCol }))
				break;
			else if (board[row][nextCol] != nullptr)
				break;
	}
}
