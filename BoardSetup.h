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
		virtual ~BoardSetup() = default;
		virtual std::list<Piece*> getPieceSet() = 0;
	};
}