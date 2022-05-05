#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupPawnsBehind : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}