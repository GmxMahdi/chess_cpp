/* Project : Chess Game Project INF1015
*  File : King.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la classe
					Piece. Elle d�finie les d�placements pour les rois.
*/

#pragma once
#include "Piece.h"

namespace GameModel 
{
	class King : public Piece
	{
	public:
		//! Constructs a king. Defaults to white.
		King() : Piece() {}

		//! Constructor of the king.
		/*!
			\param color the color of the piece.
			\param position the position of the piece of the board.
		*/
		King(Color color, Position position) : Piece(color, position) {}

		//! Create a copy of a king.
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