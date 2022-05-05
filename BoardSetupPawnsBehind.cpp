#include "BoardSetupPawnsBehind.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupPawnsBehind::getPieceSet() {
	std::cout << "[Pawns placed behind]\n";
	list<Piece*> pieces;

	pieces.push_back(new Pawn(Color::WHITE, { 7, 4 }));
	pieces.push_back(new Pawn(Color::WHITE, { 7, 5 }));
	pieces.push_back(new Pawn(Color::WHITE, { 7, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 7, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 0, 2 }));
	pieces.push_back(new Pawn(Color::BLACK, { 0, 3 }));
	pieces.push_back(new Pawn(Color::BLACK, { 0, 0 }));
	pieces.push_back(new Pawn(Color::BLACK, { 0, 7 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 6, 4 }));
	pieces.push_back(new King(Color::WHITE, { 6, 3 }));
	pieces.push_back(new King(Color::BLACK, { 1, 3 }));

	// Bishops
	pieces.push_back(new Bishop(Color::WHITE, { 6, 2 }));
	pieces.push_back(new Bishop(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Bishop(Color::BLACK, { 1, 2 }));
	pieces.push_back(new Bishop(Color::BLACK, { 1, 5 }));


	// Rooks
	pieces.push_back(new Rook(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Rook(Color::WHITE, { 6, 7 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 0 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 7 }));

	return pieces;
}