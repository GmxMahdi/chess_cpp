/* Project : Chess Game Project INF1015
*  File : Rook.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la classe
					Piece. Elle d�finie les d�placements pour les fous.
*/

#pragma once
#include "Piece.h"

namespace GameModel
{
	class Bishop : public Piece
	{
	public:
		Bishop() : Piece() {}
		Bishop(Color color, Position position) : Piece(color, position) {}

		std::unique_ptr<Piece> clone() const override;
		std::string getImageName() const override;

	protected:
		char getSymbol() const override;
		void calculatePossibleMoves(Piece* board[8][8]) override;
	};
}