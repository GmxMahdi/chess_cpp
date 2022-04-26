#include "Player.h"
#include "King.h"
#include <memory>
#include <cassert>
using namespace std;
using namespace GameModel;

Player& Player::operator=(const Player& autre)
{
	assert(1 == 1);
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
		this->_king = piece;

	this->_pieces.emplace_back(piece);
}
