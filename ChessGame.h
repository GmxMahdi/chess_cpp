#pragma once
#include "Player.h"
#include "Piece.h"

class BoardSetup;

class ChessGame
{
public:
	ChessGame(): 
		_playerWhite(Color::WHITE), _playerBlack(Color::BLACK),
		_playerPlaying(nullptr), _playerWaiting(nullptr) {

		for (int i = 0; i < BOARD_SIZE; ++i)
			for (int j = 0; j < BOARD_SIZE; ++j)
				_board[i][j] = nullptr;
	}

public:
	ChessGame& operator=(const ChessGame& autre);
	ChessGame(const ChessGame& autre);

	void setupBoard(BoardSetup* setup);
	const Piece* const getPiece(Position position) const;
	const Piece* const getPiece(int x, int y) const;

	bool movePiece(Position source, Position destination);
	Color getCurrentPlayerColor();
	void printBoard();

private:
	void setValidMovesOfAllPieces();
	void setValidMovesOfPiece(Piece& piece);
	void applyMove(Position source, Position destination);
	bool moveKeepsKingSafe(Position source, Position destination);
	void switchTurns();

private:
	static const int BOARD_SIZE = 8;
	Piece* _board[BOARD_SIZE][BOARD_SIZE];

	Player _playerWhite{Color::WHITE};
	Player _playerBlack{Color::BLACK};

	Player* _playerPlaying;
	Player* _playerWaiting;

public:
	friend class BoardSetup;
};