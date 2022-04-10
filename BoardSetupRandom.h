#pragma once
#include "BoardSetup.h"

class BoardSetupRandom : public BoardSetup
{
	std::list<std::unique_ptr<Piece>> getPieceSet() override;
};