#pragma once
#include "BoardSetup.h"

class BoardSetupClassic : public BoardSetup
{
	std::list<std::unique_ptr<Piece>> getPieceSet() override;
};