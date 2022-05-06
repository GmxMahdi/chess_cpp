/* Project : Chess Game Project INF1015
*  File : BoardSetup.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe abstraite qui est la base de
*					toutes les classes qui d�finissent un Board Setup. Elle 
					d�clare la m�thode getPieceSet() qui est override dans 
					les classes enfants. Ces classes servent � d�finir les 
					positions initales des pi�ces sur l'�ch�quier.

*/

#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include <memory>
#include <list>


namespace GameModel
{
	class BoardSetup
	{
	public:
		//! Desctructor of the board setup.
		virtual ~BoardSetup() = default;

		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet() = 0;
	};
}