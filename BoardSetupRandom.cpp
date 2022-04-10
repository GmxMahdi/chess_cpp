#include "BoardSetupRandom.h"
#include <iostream>

using namespace std;
list<unique_ptr<Piece>> BoardSetupRandom::getPieceSet() {
	std::cout << "[Random Positions]\n";
	list<unique_ptr<Piece>> pieces;
	return pieces;
}