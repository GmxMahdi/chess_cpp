#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupQueenMarathon : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}