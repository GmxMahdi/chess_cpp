#pragma once
#include "BoardSetup.h"

class BoardSetupClassic : public BoardSetup
{
	std::list<Piece*> getPieceSet() override;
};