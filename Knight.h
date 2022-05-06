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
		//! Constructor of the knight.
		Knight() : Piece() {}

		//! Constructor of the knight.
		/*!
			\param color the color of the piece.
			\param position the position of the piece of the board.
		*/
		Knight(Color color, Position position) : Piece(color, position) {}

		//! Create a copy of a knight.
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