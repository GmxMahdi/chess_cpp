/* Project : Chess Game Project INF1015
*  File : King.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier définie les méthodes contenue dans la classe
*					King, elle définie une image et un symbole pour la pièce
*					et calcule les mouvements possibles pour la pièces.
*/

#include "King.h"
#include <iostream>
using namespace std;
using namespace GameModel;

unique_ptr<Piece> King::clone() const
{
	return make_unique<King>(*this);
}

std::string King::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "lt"s : "dt"s);
	return "Chess_k" + colorName + "60.png";
}

char King::getSymbol() const
{
	return 'K';
}
void King::calculatePossibleMoves(Piece* board[8][8]) {
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();

	addMoveIfPossible(board, { row + 1, col		}); // Bottom
	addMoveIfPossible(board, { row + 1, col + 1 }); // Bottom right
	addMoveIfPossible(board, { row + 1, col - 1 }); // Bottom left

	addMoveIfPossible(board, { row - 1, col		}); // Top
	addMoveIfPossible(board, { row - 1, col + 1 }); // Top right
	addMoveIfPossible(board, { row - 1, col - 1 }); // Top left

	addMoveIfPossible(board, { row    , col + 1 }); // Right
	addMoveIfPossible(board, { row    , col - 1 }); // Left
}