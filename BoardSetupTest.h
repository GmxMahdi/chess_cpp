/* Project : Chess Game Project INF1015
*  File : BoardSetupTest.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concr�te qui h�rite de la
*					classe Board Setup, elle d�clare la m�thode getPieceSet().
*					Elle permet d'effectuer des tests. Elle ne sera pas visible
*					dans le UI.
*/

#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupTest : public BoardSetup
	{
		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet();
	};
}