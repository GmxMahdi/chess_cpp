#pragma once
#include "BoardSetup.h"

class BoardSetupRandom : public BoardSetup
{
	std::list<Piece*> getPieceSet() override;
};