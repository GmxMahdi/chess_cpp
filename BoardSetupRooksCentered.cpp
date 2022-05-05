#include "BoardSetupRooksCentered.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupRooksCentered::getPieceSet() {
	std::cout << "[Rooks centered in the middle]\n";
	list<Piece*> pieces;


	// Pawns
	//for (int i = 0; i < 8; ++i)
	//{
	//	pieces.push_backnewPawn(Color::WHITE, { 6, i })));
	//	pieces.push_backnewPawn(Color::BLACK, { 1, i })));
	//}
	pieces.push_back(new Pawn(Color::WHITE, { 6, 3 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 2 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 4 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 0 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 7 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 4 }));
	pieces.push_back(new King(Color::WHITE, { 7, 3 }));
	pieces.push_back(new King(Color::BLACK, { 0, 3 }));

	// Bishops
	pieces.push_back(new Bishop(Color::WHITE, { 7, 2 }));
	pieces.push_back(new Bishop(Color::WHITE, { 7, 5 }));
	pieces.push_back(new Bishop(Color::BLACK, { 0, 2 }));
	pieces.push_back(new Bishop(Color::BLACK, { 0, 5 }));


	// Rooks
	pieces.push_back(new Rook(Color::WHITE, { 6, 4 }));
	pieces.push_back(new Rook(Color::WHITE, { 7, 3 }));
	pieces.push_back(new Rook(Color::BLACK, { 0, 4 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 3 }));

	return pieces;
}