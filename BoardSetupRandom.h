#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupRandom : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}