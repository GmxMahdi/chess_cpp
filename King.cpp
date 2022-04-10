#include "King.h"
#include <iostream>
using namespace std;

unique_ptr<Piece> King::clone() const
{
	return make_unique<King>(*this);
}

std::string King::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "white"s : "black"s);
	return "king_" + colorName + ".png";
}

char King::getSymbol() const
{
	return 'K';
}
void King::calculatePossibleMoves(Piece* board[8][8]) {
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();

	addMoveIfPossible(board, { row + 1, col		});
	addMoveIfPossible(board, { row + 1, col + 1 });
	addMoveIfPossible(board, { row + 1, col - 1 });

	addMoveIfPossible(board, { row - 1, col		});
	addMoveIfPossible(board, { row - 1, col + 1 });
	addMoveIfPossible(board, { row - 1, col - 1 });

	addMoveIfPossible(board, { row    , col + 1 });
	addMoveIfPossible(board, { row    , col - 1 });
}