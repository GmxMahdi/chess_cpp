/* Project : Chess Game Project INF1015
*  File : BoardSetupPawnsBehind.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la
*					classe Board Setup, elle d�clare la m�thode getPieceSet()
*					qui est d�finie dans BoardSetupPawnsBehind.cpp qui d�finie
*					les positions initiales des pi�ces pour le mode de jeux
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