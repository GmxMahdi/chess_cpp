#include "Player.h"
#include "King.h"
#include <memory>

using namespace std;

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
