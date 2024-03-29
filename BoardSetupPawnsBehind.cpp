/* Project : Chess Game Project INF1015
*  File : BoardSetupPawnsBehind.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Dans ce fichier, la classe d�finie la m�thode getPieceSet()
*					qui d�finie les positions initiales des pi�ces pour le mode
					de jeux Pawns Behind, les pions vont �tre plac�s derri�re
					les autres pi�ces vont �tre	devant.
*/

#include "BoardSetupPawnsBehind.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupPawnsBehind::getPieceSet() {
	std::cout << "[Pawns placed behind]\n";
	list<Piece*> pieces;

	for (int i = 0; i < 8; ++i)
	{
		pieces.push_back(new Pawn(Color::WHITE, { 7, i }));
		pieces.push_back(new Pawn(Color::BLACK, { 0, i }));
	}

	// Kings
	pieces.push_back(new King(Color::WHITE, { 6, 4 }));
	pieces.push_back(new King(Color::BLACK, { 1, 3 }));

	// Bishops
	pieces.push_back(new Bishop(Color::WHITE, { 6, 2 }));
	pieces.push_back(new Bishop(Color::BLACK, { 1, 2 }));

	// Knights
	pieces.push_back(new Knight(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Knight(Color::BLACK, { 1, 5 }));


	// Rooks
	pieces.push_back(new Rook(Color::WHITE, { 6, 1 }));
	pieces.push_back(new Rook(Color::WHITE, { 6, 7 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 0 }));
	pieces.push_back(new Rook(Color::BLACK, { 1, 6 }));

	return pieces;
}