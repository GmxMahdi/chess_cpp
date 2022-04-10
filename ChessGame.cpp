#include "ChessGame.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include <iostream>
#include <memory>
#include <windows.h>
#include "BoardSetup.h"

using namespace std;

ChessGame& ChessGame::operator=(const ChessGame& autre)
{
	if (this != &autre) {
		_playerWhite = autre._playerWhite;
		_playerBlack = autre._playerBlack;

		if (autre._playerPlaying->_color == Color::WHITE)
		{
			_playerPlaying = &_playerWhite;
			_playerWaiting = &_playerBlack;
		}
		else
		{
			_playerPlaying = &_playerBlack;
			_playerWaiting = &_playerWhite;
		}

		for (auto&& piece : _playerWhite._pieces)
			if (piece->_isAlive)
				_board[piece->getPosition().getRow()][piece->getPosition().getCol()] = piece.get();

		for (auto&& piece : _playerBlack._pieces)
			if (piece->_isAlive)
				_board[piece->getPosition().getRow()][piece->getPosition().getCol()] = piece.get();
	}
	return *this;
}

ChessGame::ChessGame(const ChessGame& autre)
{
	*this = autre;
}

void ChessGame::setupBoard(BoardSetup* setup)
{
	_playerPlaying = &_playerWhite;
	_playerWaiting = &_playerBlack;

	list<unique_ptr<Piece>> pieces = setup->getPieceSet();

	for (auto&& piece : pieces)
	{
		_board[piece->_position.getRow()][piece->_position.getCol()] = piece.get();

		if (piece->_color == Color::WHITE)
		{
			if (dynamic_cast<King*>(piece.get()) != nullptr)
				_playerWhite._king = piece.get();
			_playerWhite._pieces.push_back(move(piece));
		}
		else
		{
			if (dynamic_cast<King*>(piece.get()) != nullptr)
				_playerBlack._king = piece.get();
			_playerBlack._pieces.push_back(move(piece));
		}
	}

	setValidMovesOfAllPieces();
}

const Piece* const ChessGame::getPiece(Position position) const
{
	return getPiece(position.getRow(), position.getCol());
}

const Piece* const ChessGame::getPiece(int row, int col) const
{
	if (row >= 0 && row < BOARD_SIZE &&
		col >= 0 && col < BOARD_SIZE)
		return _board[row][col];
	
	return nullptr;
}

bool ChessGame::movePiece(Position source, Position destination)
{
	Piece* piece = _board[source.getRow()][source.getCol()];
	if (piece == nullptr)
		return false;

	if (piece->_moves.find(destination) == piece->_moves.end())
		return false;


	applyMove(source, destination);
	switchTurns();
	setValidMovesOfAllPieces();

	return true;
}

Color ChessGame::getCurrentPlayerColor()
{
	return _playerPlaying->_color;
}

void ChessGame::applyMove(Position source, Position destination)
{
	Piece* piece = _board[source.getRow()][source.getCol()];
	_board[source.getRow()][source.getCol()] = nullptr; // Lift piece

	piece->_position.set(destination);  // Change its position
	
	Piece* pieceOnDestination = _board[destination.getRow()][destination.getCol()];
	if (pieceOnDestination != nullptr)
		pieceOnDestination->_isAlive = false;

	_board[destination.getRow()][destination.getCol()] = piece; // Drop piece
}

bool ChessGame::moveKeepsKingSafe(Position source, Position destination)
{
	ChessGame gameCopy = *this;
	gameCopy.applyMove(source, destination);
	for (auto& piece : gameCopy._playerWaiting->_pieces)
	{
		piece->calculatePossibleMoves(gameCopy._board);
		if (piece->_moves.find(gameCopy._playerPlaying->_king->_position) != piece->_moves.end())
			return false;
	}
	return true;
}

void ChessGame::switchTurns()
{
	Player* temp = _playerPlaying;
	_playerPlaying = _playerWaiting;
	_playerWaiting = temp;
}

void ChessGame::setValidMovesOfAllPieces()
{
	for (unique_ptr<Piece>& piece : _playerWaiting->_pieces)
		piece->_moves.clear();

	for (unique_ptr<Piece>& piece : _playerPlaying->_pieces)
		setValidMovesOfPiece(*piece);
}

void ChessGame::setValidMovesOfPiece(Piece& piece)
{
	piece.calculatePossibleMoves(_board);

	auto itr = piece._moves.begin();
	while (itr != piece._moves.end())
	{
		auto move = *(itr++);
		if (!moveKeepsKingSafe(piece._position, move))
			piece._moves.erase(move);
	}
}

void ChessGame::printBoard()
{
	unordered_set<Position> allMoves;
	for (auto& piece : _playerPlaying->_pieces)
	{
		cout << "Piece: " << piece->getSymbol() << ", Moves = " << piece->_moves.size() << "\n";
		auto itr = piece->getPossibleMoves();
		allMoves.insert(itr.begin(), itr.end());
	}

	cout << allMoves.size() << ": size\n";

	cout << "   0 1 2 3 4 5 6 7 \n";
	for (int row = 0; row < 8; ++row)
	{
		cout << row << " [";
		for (int col = 0; col < 8; ++col)
		{
			Piece* piece = _board[row][col];
			if (allMoves.find({ row,col }) != allMoves.end())
			{
				if (piece == nullptr)
					cout << "\033[32;1;5mX\033[0m ";
				else
					cout << "\033[91;1;5mX\033[0m ";
			}
			else 
			{
				if (piece == nullptr) 
					cout << "  ";
				else 
					cout << piece->getAscii() << " ";
			}

		}
		cout << "]\n";
	}
}
