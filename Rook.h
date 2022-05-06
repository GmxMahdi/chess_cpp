/* Project : Chess Game Project INF1015
*  File : Rook.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la classe 
					Piece. Elle définie les déplacements pour les tours.
*/

#pragma once
#include "Piece.h"

namespace GameModel
{
	class Rook : public Piece
	{
	public:
		//! Constructs a rook. Defaults to white.
		Rook() : Piece() {}

		//! Constructor of the rook.
		/*!
			\param color the color of the piece.
			\param position the position of the piece of the board.
		*/
		Rook(Color color, Position position) : Piece(color, position) {}

		//! Create a copy of a rook.
		std::unique_ptr<Piece> clone() const override;

		//! Gets the file name of an image of the piece.
		std::string getImageName() const override;

	protected:
		//! Char representation of a piece.
		char getSymbol() const override;

		//! Calculates the possibles moves the piece can do on the board.
		//! Fills it's move list with the avaiable positions.
		/*!
			\param board chess board in which the piece is placed in.
		*/
		void calculatePossibleMoves(Piece* board[8][8]) override;
	};
}