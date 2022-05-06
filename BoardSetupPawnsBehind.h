/* Project : Chess Game Project INF1015
*  File : BoardSetupPawnsBehind.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la
*					classe Board Setup, elle déclare la méthode getPieceSet()
*					qui est définie dans BoardSetupPawnsBehind.cpp qui définie
*					les positions initiales des pièces pour le mode de jeux
*					Pawns Behind.
*/

#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupPawnsBehind : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}