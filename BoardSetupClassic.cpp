#include "BoardSetupClassic.h"
#include <iostream>

using namespace std;

list<unique_ptr<Piece>> BoardSetupClassic::getPieceSet() {
	std::cout << "[Classic Positions]\n";
	list<unique_ptr<Piece>> pieces;


	// Pawns
	for (int i = 0; i < 8; ++i)
	{
		pieces.push_back(make_unique<Pawn>(Pawn(Color::WHITE, { 6, i })));
		pieces.push_back(make_unique<Pawn>(Pawn(Color::BLACK, { 1, i })));
	}

	// Kings
	pieces.push_back(make_unique<King>(King(Color::WHITE, { 7, 4 })));
	pieces.push_back(make_unique<King>(King(Color::BLACK, { 0, 3 })));

	// Bishops
	pieces.push_back(make_unique<Bishop>(Bishop(Color::WHITE, { 7, 2 })));
	pieces.push_back(make_unique<Bishop>(Bishop(Color::WHITE, { 7, 5 })));
	pieces.push_back(make_unique<Bishop>(Bishop(Color::BLACK, { 0, 2 })));
	pieces.push_back(make_unique<Bishop>(Bishop(Color::BLACK, { 0, 5 })));

	return pieces;
}