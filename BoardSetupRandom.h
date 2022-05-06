/* Project : Chess Game Project INF1015
*  File : BoardSetupRandom.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la
*					classe Board Setup, elle d�clare la m�thode getPieceSet()
*					qui est d�finie dans BoardSetupRandom.cpp qui d�finie
*					les positions initiales des pi�ces pour le mode de jeux
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