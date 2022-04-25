#pragma once
#include "ChessGame.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include <memory>
#include <list>
class BoardSetup
{
public:
	virtual std::list<Piece*> getPieceSet() = 0;
};