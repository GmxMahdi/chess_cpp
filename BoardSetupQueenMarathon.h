/* Project : Chess Game Project INF1015
*  File : BoardSetupQueenMarathon.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la
*					classe Board Setup, elle d�clare la m�thode getPieceSet()
*					qui est d�finie dans BoardSetupQueenMarathon.cpp qui d�finie
*					les positions initiales des pi�ces pour le mode de jeux
*					Queen Marathon.
*/

#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupQueenMarathon : public BoardSetup
	{
		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet();
	};
}