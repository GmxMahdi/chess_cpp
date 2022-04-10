#include "Pawn.h"
#include <iostream>
using namespace std;

unique_ptr<Piece> Pawn::clone() const
{
	return make_unique<Pawn>(*this);
}

std::string Pawn::getImageName() const
{
	auto colorName = (_color == Color::WHITE ? "white"s : "black"s);
	return "pawn_" + colorName + ".png";
}

char Pawn::getSymbol() const
{
	return 'P';
}

void Pawn::calculatePossibleMoves(Piece* board[8][8]) {
	_moves.clear();
	if (!_isAlive) return;

	int row = _position.getRow();
	int col = _position.getCol();

	if (_color == Color::WHITE)
	{
		if (row != 0)
		{
			if (board[row - 1][col] == nullptr)
			{
				_moves.insert({ row - 1, col });

				if (row == 6)
					if (board[4][col] == nullptr)
						_moves.insert({ 4, col });
			}

			if (col != 0)
			{
				Piece* piece = board[row - 1][col - 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row - 1][col - 1]))
						_moves.insert({ row - 1, col - 1 });
			}
					
			if (col != 7)
			{
				Piece* piece = board[row - 1][col + 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row - 1][col + 1]))
						_moves.insert({ row - 1, col + 1 });
			}
		}
	}
	else if (_color == Color::BLACK)
	{
		if (row != 7)
		{
			if (board[row + 1][col] == nullptr)
			{
				_moves.insert({ row + 1, col });

				if (row == 1)
					if (board[3][col] == nullptr)
						_moves.insert({ 3, col });
			}


			if (col != 0)
			{
				Piece* piece = board[row + 1][col - 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row + 1][col - 1]))
						_moves.insert({ row + 1, col - 1 });
			}

			if (col != 7)
			{
				Piece* piece = board[row + 1][col + 1];
				if (piece != nullptr)
					if (!hasSameColorOfOtherPiece(board[row + 1][col + 1]))
						_moves.insert({ row + 1, col + 1 });
			}
		}
	}
}