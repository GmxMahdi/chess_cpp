#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include <memory>
#include <list>


namespace GameModel
{
	class BoardSetup
	{
	public:
		virtual std::list<Piece*> getPieceSet() = 0;
	};
}