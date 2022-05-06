/* Project : Chess Game Project INF1015
*  File : Pawn.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier définie les méthodes contenue dans la classe
*					Pawn, elle définie une image et un symbole pour la pièce
*					et calcule les mouvements possibles pour la pièces.
*/

#include "Pawn.h"
#include <iostream>
using namespace std;
using namespace GameModel;

unique_ptr<Piece> Pawn::clone() const
{
	return make_unique<Pawn>(*this);
}

std::string Pawn::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "lt"s : "dt"s);
	return "Chess_p" + colorName + "60.png";
}

char Pawn::getSymbol() const
{
	return 'P';
}

void Pawn::calculatePossibleMoves(Piece* board[8][8]) {
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();

	if (_color == Color::WHITE)
	{
		// If pawn is not at the other side of the board
		if (row != 0)
		{
			// If there is no piece in front of the pawn
			if (board[row - 1][col] == nullptr)
			{
				_moves.insert({ row - 1, col });

				// If pawn is that the starting position
				if (row == 6)
					// If there is no piece in front-front of the pawn
					if (board[4][col] == nullptr)
						_moves.insert({ 4, col });
			}

			// If pawn isn't completely to the left
			if (col != 0)
			{
				// Get piece on the top left relative to the pawn
				Piece* piece = board[row - 1][col - 1];

				// If there is a piece and it's the opposite color
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row - 1][col - 1]))
						_moves.insert({ row - 1, col - 1 });
			}
					
			// If pawn isn't completely to the right
			if (col != 7)
			{
				// Get piece on the top right relative to the pawn
				Piece* piece = board[row - 1][col + 1];

				// If there is a piece and it's the opposite color
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row - 1][col + 1]))
						_moves.insert({ row - 1, col + 1 });
			}
		}
	}

	// Same rules but with the black pawns
	else if (_color == Color::BLACK)
	{
		if (row != 7)
		{
			if (board[row + 1][col] == nullptr)
			{
				_moves.insert({ row + 1, col });

				if (row == 1)
					if (board[3][col] == nullptr)
						_moves.insert({ 3, col });
			}


			if (col != 0)
			{
				Piece* piece = board[row + 1][col - 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row + 1][col - 1]))
						_moves.insert({ row + 1, col - 1 });
			}

			if (col != 7)
			{
				Piece* piece = board[row + 1][col + 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row + 1][col + 1]))
						_moves.insert({ row + 1, col + 1 });
			}
		}
	}
}