/* Project : Chess Game Project INF1015
*  File : DisposableMove.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe permet d'appliquer un mouvement temporaire sur 
					l'équichier. Lors de la destruction de l'instance, le 
					mouvement est défait.
*/

#pragma once
#include "Piece.h"
namespace GameModel
{
	class DisposableMove
	{
		public:
			DisposableMove(Piece* piece, Piece* (&board)[8][8]);


			void movePiece(Position dst);
			~DisposableMove();
		private:
			Piece* (&_board)[8][8];
			Position _srcPos;
			Position _dstPos;
			Piece* _pieceToMove;
			Piece* _pieceSteppedOn;		
	};
}

