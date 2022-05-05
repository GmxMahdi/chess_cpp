#include "BoardSetupOn3Levels.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupOn3Levels::getPieceSet() {
	std::cout << "[Positions on three levels]\n";
	list<Piece*> pieces;

	pieces.push_back(new Pawn(Color::WHITE, { 5, 4 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 5, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 2 }));
	pieces.push_back(new Pawn(Color::BLACK, { 2, 3 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 0 }));
	pieces.push_back(new Pawn(Color::BLACK, { 2, 7 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 4 }));
	pieces.push_back(new King(Color::WHITE, { 7, 3 }));
	pieces.push_back(new King(Color::BLACK, { 0, 3 }));

	// Bishops
	pieces.push_back(new Bishop(Color::WHITE, { 7, 2 }));
	pieces.push_back(new Bishop(Color::WHITE, { 5, 5 }));
	pieces.push_back(new Bishop(Color::BLACK, { 0, 2 }));
	pieces.push_back(new Bishop(Color::BLACK, { 2, 5 }));


	// Rooks
	pieces.push_back(new Rook(Color::WHITE, { 7, 0 }));
	pieces.push_back(new Rook(Color::WHITE, { 7, 7 }));
	pieces.push_back(new Rook(Color::BLACK, { 0, 0 }));
	pieces.push_back(new Rook(Color::BLACK, { 0, 7 }));

	return pieces;
}