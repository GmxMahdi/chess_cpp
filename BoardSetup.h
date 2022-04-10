#pragma once
#include "ChessGame.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include <memory>
#include <list>
class BoardSetup
{
public:
	virtual std::list<std::unique_ptr<Piece>> getPieceSet() = 0;
};