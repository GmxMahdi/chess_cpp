#include "BoardSetupRandom.h"
#include <iostream>

using namespace std;
using namespace GameModel;

list<Piece*> BoardSetupRandom::getPieceSet() {
	srand(time(NULL));
	std::cout << "[Random Positions]\n";
	list<Piece*> pieces;


	// Kings
	pieces.push_back(new King(Color::WHITE, { 7, 0 }));
	pieces.push_back(new King(Color::BLACK, { 0, 7 }));

	// Pawns
	pieces.push_back(new Pawn(Color::WHITE, { 6, 0 }));
	pieces.push_back(new Pawn(Color::WHITE, { 6, 1 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 7 }));
	pieces.push_back(new Pawn(Color::BLACK, { 1, 6 }));


	const int MIN_PIECE_COUNT = 3;
	const int MAX_PIECE_COUNT = 10;
	const int INTERVAL = MAX_PIECE_COUNT - MIN_PIECE_COUNT;
	int pieceCount = (rand() % INTERVAL) + MIN_PIECE_COUNT;

	std::vector<Position> whitePositions = generateAvailablePositionsWhiteSide(pieceCount);
	std::vector<Position> blackPositions = generateAvailablePositionsBlackSide(pieceCount);

	for (int i = 0; i < pieceCount; ++i)
	{
		std::list<Piece*> piecesType = 
			generateRandomBlackAndWhitePiece(whitePositions[i], blackPositions[i]);
		for (auto& piece : piecesType)
			pieces.push_back(piece);
	}

	return pieces;
}

std::vector<Position> GameModel::BoardSetupRandom::generateAvailablePositionsWhiteSide(int count)
{
	std::vector<Position> availablePositions;
	for (int row = 4; row < 6; ++row)
		for (int col = 0; col < 8; ++col)
			availablePositions.push_back(Position(row, col));


	for (int row = 6; row < 8; ++row)
		for (int col = 2; col < 8; ++col)
			availablePositions.push_back(Position(row, col));

	std::vector<Position> chosenPositions;
	for (int i = 0; i < count; ++i)
	{
		int positionIndex = rand() % availablePositions.size();
		auto positionItr = availablePositions.begin() + positionIndex;
		chosenPositions.push_back(*positionItr);
		availablePositions.erase(positionItr);

	}
	return chosenPositions;
}

std::vector<Position> GameModel::BoardSetupRandom::generateAvailablePositionsBlackSide(int count)
{
	std::vector<Position> availablePositions;
	for (int row = 2; row < 4; ++row)
		for (int col = 0; col < 8; ++col)
			availablePositions.push_back(Position(row, col));


	for (int row = 0; row < 2; ++row)
		for (int col = 0; col < 6; ++col)
			availablePositions.push_back(Position(row, col));

	std::vector<Position> chosenPositions;
	for (int i = 0; i < count; ++i)
	{
		int positionIndex = rand() % availablePositions.size();
		auto positionItr = availablePositions.begin() + positionIndex;
		chosenPositions.push_back(*positionItr);
		availablePositions.erase(positionItr);

	}
	return chosenPositions;
}

std::list<Piece*> GameModel::BoardSetupRandom::generateRandomBlackAndWhitePiece(Position whitePosition, Position blackPosition)
{
	const int PIECE_TYPE_COUNT = 3;
	int pieceIndex = rand() % PIECE_TYPE_COUNT;

	switch (pieceIndex)
	{
	case 0:
		return
		{
			new Pawn(Color::WHITE, whitePosition),
			new Pawn(Color::BLACK, blackPosition)
		};
	case 1:
		return
		{
			new Bishop(Color::WHITE, whitePosition),
			new Bishop(Color::BLACK, blackPosition)
		};
	case 2:
		return
		{
			new Rook(Color::WHITE, whitePosition),
			new Rook(Color::BLACK, blackPosition)
		};
	}
	throw logic_error("Piece index was greater than avaiable type of pieces.");
}
