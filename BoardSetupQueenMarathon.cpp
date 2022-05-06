/* Project : Chess Game Project INF1015
*  File : BoardSetupQueenMarathon.cpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Dans ce fichier, la classe définie la méthode getPieceSet()
*					qui définie les positions initiales des pièces pour le mode
					de jeux Queen Marathon, il y aura plusieurs reines placées 
					sur 3 niveaux différents et protégées par des pions ainsi 
					qu'un roi placé au premier niveau.
*/

#include "BoardSetupQueenMarathon.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupQueenMarathon::getPieceSet() {
	std::cout << "[Queen Marathon]\n";
	list<Piece*> pieces;

	pieces.push_back(new Pawn(Color::WHITE, { 7, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 7, 7 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 1 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 6 }));
	pieces.push_back(new Pawn(Color::WHITE, { 5, 2 }));
	pieces.push_back(new Pawn(Color::WHITE, { 5, 5 }));
	pieces.push_back(new Pawn(Color::WHITE, { 4, 3 }));
	pieces.push_back(new Pawn(Color::WHITE, { 4, 4 }));

	pieces.push_back(new Pawn(Color::BLACK, { 0, 0 }));
	pieces.push_back(new Pawn(Color::BLACK, { 0, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 1 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 6 }));
	pieces.push_back(new Pawn(Color::BLACK, { 2, 2 }));
	pieces.push_back(new Pawn(Color::BLACK, { 2, 5 }));
	pieces.push_back(new Pawn(Color::BLACK, { 3, 3 }));
	pieces.push_back(new Pawn(Color::BLACK, { 3, 4 }));

	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 4 }));
	pieces.push_back(new King(Color::BLACK, { 0, 4 }));

	// Queens
	pieces.push_back(new Queen(Color::WHITE, { 7, 1 }));
	pieces.push_back(new Queen(Color::WHITE, { 7, 6 }));
	pieces.push_back(new Queen(Color::WHITE, { 6, 2 }));
	pieces.push_back(new Queen(Color::WHITE, { 6, 5 }));
	pieces.push_back(new Queen(Color::WHITE, { 5, 3 }));
	pieces.push_back(new Queen(Color::WHITE, { 5, 4 }));

	pieces.push_back(new Queen(Color::BLACK, { 0, 1 }));
	pieces.push_back(new Queen(Color::BLACK, { 0, 6 }));
	pieces.push_back(new Queen(Color::BLACK, { 1, 2 }));
	pieces.push_back(new Queen(Color::BLACK, { 1, 5 }));
	pieces.push_back(new Queen(Color::BLACK, { 2, 3 }));
	pieces.push_back(new Queen(Color::BLACK, { 2, 4 }));


	return pieces;
}