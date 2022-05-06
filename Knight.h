#pragma once
#include "Piece.h"

namespace GameModel
{
	class Knight : public Piece
	{
	public:
		Knight() : Piece() {}
		Knight(Color color, Position position) : Piece(color, position) {}

		std::unique_ptr<Piece> clone() const override;
		std::string getImageName() const override;

	protected:
		char getSymbol() const override;
		void calculatePossibleMoves(Piece* board[8][8]) override;
	};
}