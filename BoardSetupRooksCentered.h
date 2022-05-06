/* Project : Chess Game Project INF1015
*  File : BoardSetupRooksCentered.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la	
*					classe Board Setup, elle déclare la méthode getPieceSet()
*					qui est définie dans BoardSetupRooksCentered.cpp qui définie
*					les positions initiales des pièces pour le mode de jeux 
*					Rooks Centered.
*/
#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupRooksCentered : public BoardSetup
	{
		//! Gives a set of pieces to be used on a board.
		/*!
			\returns list of pieces.
		*/
		virtual std::list<Piece*> getPieceSet();
	};
}