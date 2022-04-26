#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupClassic : public BoardSetup
	{
		std::list<Piece*> getPieceSet() override;
	};
}