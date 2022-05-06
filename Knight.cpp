/* Project : Chess Game Project INF1015
*  File : Knight.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Ce fichier d�finie les m�thodes contenue dans la classe
*					Knight, elle d�finie une image et un symbole pour la pi�ce
*					et calcule les mouvements possibles pour la pi�ces.
*/

#include "Knight.h"

using namespace std;
using namespace GameModel;
unique_ptr<Piece> Knight::clone() const
{
	return make_unique<Knight>(*this);
}

std::string Knight::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "lt"s : "dt"s);
	return "Chess_n" + colorName + "60.png";
}

char Knight::getSymbol() const
{
	return 'N';
}

void Knight::calculatePossibleMoves(Piece* board[8][8])
{
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();

	for (int rowSide = -1; rowSide <= 1; rowSide += 2)
		for (int colSide = -1; colSide <= 1; colSide += 2)
		{
			addMoveIfPossible(board, { row + 2 * rowSide, col + 1 * colSide });
			addMoveIfPossible(board, { row + 1 * rowSide, col + 2 * colSide });

		}
}
