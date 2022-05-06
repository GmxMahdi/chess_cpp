/* Project : Chess Game Project INF1015
*  File : BoardSetupTest.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe concrète qui hérite de la
*					classe Board Setup, elle déclare la méthode getPieceSet().
*					Elle permet d'effectuer des tests. Elle ne sera pas visible
*					dans le UI.
*/

#include "BoardSetupTest.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupTest::getPieceSet() {
	std::cout << "[Test Positions]\n";
	list<Piece*> pieces;


	// Pawns
	pieces.push_back(new Pawn(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 1 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 1 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 0 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 0 }));
	pieces.push_back(new King(Color::BLACK, { 0, 0 }));

	// Knights
	pieces.push_back(new Knight(Color::WHITE, { 7, 1 }));
	pieces.push_back(new Knight(Color::BLACK, { 0, 1 }));

	// Queens
	pieces.push_back(new Queen(Color::WHITE, { 7, 7 }));
	pieces.push_back(new Queen(Color::BLACK, { 0, 7 }));

	return pieces;
}