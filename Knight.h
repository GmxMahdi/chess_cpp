/* Project : Chess Game Project INF1015
*  File : Knight.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la classe
					Piece. Elle définie les déplacements pour les chevaliers.
*/

#pragma once
#include "Piece.h"

namespace GameModel
{
	class Knight : public Piece
	{
	public:
		Knight() : Piece() {}
		Knight(Color color, Position position) : Piece(color, position) {}

		std::unique_ptr<Piece> clone() const override;
		std::string getImageName() const override;

	protected:
		char getSymbol() const override;
		void calculatePossibleMoves(Piece* board[8][8]) override;
	};
}