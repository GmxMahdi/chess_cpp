#pragma once
#include "BoardSetup.h"

namespace GameModel
{
	class BoardSetupRandom : public BoardSetup
	{
	public:
		std::list<Piece*> getPieceSet() override;

	private:
		std::vector<Position> generateAvailablePositionsWhiteSide(int count);
		std::vector<Position> generateAvailablePositionsBlackSide(int count);
		std::list<Piece*> generateRandomBlackAndWhitePiece(Position whitePosition, Position blackPosition);
	};
}