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
		std::list<Piece*> getPieceSet() override;

	private:
		std::vector<Position> generateAvailablePositionsWhiteSide(int count);
		std::vector<Position> generateAvailablePositionsBlackSide(int count);
		std::list<Piece*> generateRandomBlackAndWhitePiece(Position whitePosition, Position blackPosition);
	};
}