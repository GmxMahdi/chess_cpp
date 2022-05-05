#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupOn3Levels : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}