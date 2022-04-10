#pragma once
#include "Piece.h"
#include "Color.h"
#include <vector>
#include <memory>
#include <list>
class Player
{
public:
	Player(Color color): _color(color), _pieces(), _king(nullptr) {
		_pieces.clear();
	}

	Player& operator=(const Player& autre);
	Player(const Player& autre);

	const std::list<std::unique_ptr<Piece>>& getPieces() const { return _pieces;  }

private:
	friend class ChessGame;

	Color								_color;
	std::list<std::unique_ptr<Piece>>	_pieces;
	Piece*								_king;
};