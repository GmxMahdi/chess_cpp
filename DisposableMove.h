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
			//! Constructor of a disposable move.
			/*!
				\param piece piece to be moved.
				\param board reference to the board in which the piece is placed.
			*/
			DisposableMove(Piece* piece, Piece* (&board)[8][8]);

			//! Moves a piece to a destination position.
			//! Must be called only once.
			/*!
				\param dst destination position of the piece.
			*/
			void movePiece(Position dst);

			//! Deconstructor of the instance
			//! Undos the move that was made.
			~DisposableMove();

		private:
			Piece* (&_board)[8][8]; /**< Reference of the board */
			Position _srcPos;		/**< Initial position of the piece */
			Position _dstPos;		/**< Final position of the piece */
			Piece* _pieceToMove;	/**< Piece that is moved */
			Piece* _pieceSteppedOn;	/**< Piece that was capured after the move */
	};
}

