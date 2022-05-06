#include "BoardSetupRooksCentered.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupRooksCentered::getPieceSet() {
	std::cout << "[Rooks centered in the middle]\n";
	list<Piece*> pieces;

	pieces.push_back(new Pawn(Color::WHITE, { 6, 2 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 7 }));
	pieces.push_back(new Pawn(Color::WHITE, { 4, 3 }));
	pieces.push_back(new Pawn(Color::WHITE, { 4, 4 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 5 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 2 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 0 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 3, 3 }));
	pieces.push_back(new Pawn(Color::BLACK, { 3, 4 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 4 }));
	pieces.push_back(new King(Color::BLACK, { 0, 4 }));

	// Knights
	pieces.push_back(new Knight(Color::WHITE, { 7, 2 }));
	pieces.push_back(new Knight(Color::WHITE, { 7, 5 }));
	pieces.push_back(new Knight(Color::WHITE, { 7, 1 }));
	pieces.push_back(new Knight(Color::WHITE, { 7, 6 }));
	pieces.push_back(new Knight(Color::BLACK, { 0, 2 }));
	pieces.push_back(new Knight(Color::BLACK, { 0, 5 }));
	pieces.push_back(new Knight(Color::BLACK, { 0, 1 }));
	pieces.push_back(new Knight(Color::BLACK, { 0, 6 }));


	// Rooks
	pieces.push_back(new Rook(Color::WHITE, { 6, 4 }));
	pieces.push_back(new Rook(Color::WHITE, { 6, 3 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 4 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 3 }));

	return pieces;
}