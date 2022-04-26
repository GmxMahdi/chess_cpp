#pragma once
#include "Piece.h"
namespace GameModel
{
	// CECI EST LA CLASSE POUR LE RAII
	// DESOLER CEST UN PEU PROCHE L'INIT ON A FAIT CA DERNIERE MINUTE MAIS CA MARCHE!!
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

