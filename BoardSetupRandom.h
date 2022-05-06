/* Project : Chess Game Project INF1015
*  File : BoardSetupRandom.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la
*					classe Board Setup, elle déclare la méthode getPieceSet()
*					qui est définie dans BoardSetupRandom.cpp qui définie
*					les positions initiales des pièces pour le mode de jeux
*					Random.
*/
#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupRandom : public BoardSetup
	{
	public:
		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet();

	private:
		//! Generates a number of positions on the white side.
		/*!
			\param count number of positions to generate
			\returns vector of positions.
		*/
		std::vector<Position> generateAvailablePositionsWhiteSide(int count);

		//! Generates a number of positions on the black side.
		/*!
			\param count number of positions to generate
			\returns vector of positions.
		*/
		std::vector<Position> generateAvailablePositionsBlackSide(int count);

		//! Generates the same piece type for both black and white
		//! and assigns their position
		/*!
			\param whitePosition position for the white piece
			\param blackPosition position for the black piece
			\returns a white piece and a black piece of the same type.
		*/
		std::list<Piece*> generateRandomBlackAndWhitePiece(Position whitePosition, Position blackPosition);
	};
}