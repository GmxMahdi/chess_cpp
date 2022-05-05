#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupRooksCentered : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}