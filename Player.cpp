#include "Player.h"
#include "King.h"
#include "TooManyKingsException.h"
#include <memory>
#include <cassert>
using namespace std;
using namespace GameModel;

Player& Player::operator=(const Player& autre)
{
	if (this != &autre) 
		for (auto&& piece : autre._pieces)
		{
			unique_ptr<Piece> copy = piece->clone();
			if (dynamic_cast<King*>(copy.get()) != nullptr)
				_king = copy.get();
			_pieces.push_back(move(copy));
		}
	return *this;
}

Player::Player(const Player& autre)
{
	*this = autre;
}

void Player::addPiece(Piece* piece)
{
	// If the piece is a king, set _king
	if (dynamic_cast<King*>(piece) != nullptr)
	{
		++kingCount;
		if (kingCount > 1)
			throw TooManyKingsException(
				"The "s + (this->_color == Color::WHITE ? "white" : "black") + " player attempted to hold " +
				"more than one king. The extra king was removed. ");
		this->_king = piece;
	}

	this->_pieces.emplace_back(piece);
}
