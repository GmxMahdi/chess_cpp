/* Project : Chess Game Project INF1015
*  File : BoardSetupClassic.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la
*					classe Board Setup, elle d�clare la m�thode getPieceSet()
*					qui est d�finie dans BoardSetupClassic.cpp qui d�finie
*					les positions initiales des pi�ces pour le mode de jeux
*					Classic.
*/

#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupClassic : public BoardSetup
	{
		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet();
	};
}