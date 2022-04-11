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

		// Copy players
		_playerWhite = autre._playerWhite;
		_playerBlack = autre._playerBlack;

		// Set who is playing, who is waiting
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

		// Place white pieces on the board
		for (auto&& piece : _playerWhite._pieces)
			if (piece->_isAlive)
				_board[piece->getPosition().getRow()][piece->getPosition().getCol()] = piece.get();

		// Place black pieces on the board
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
	// Set who is playing first, who is waiting
	_playerPlaying = &_playerWhite;
	_playerWaiting = &_playerBlack;

	// Get the pieces from the BoardSetup class
	list<unique_ptr<Piece>> pieces = setup->getPieceSet();

	for (auto&& piece : pieces)
	{
		// Place piece on the board
		_board[piece->_position.getRow()][piece->_position.getCol()] = piece.get();

		if (piece->_color == Color::WHITE)
		{
			// If the piece is a king, set _king
			if (dynamic_cast<King*>(piece.get()) != nullptr)
				_playerWhite._king = piece.get();

			// Give the piece to the white player
			_playerWhite._pieces.push_back(move(piece));
		}
		else
		{
			// If the piece is a king, set _king
			if (dynamic_cast<King*>(piece.get()) != nullptr)
				_playerBlack._king = piece.get();

			// Give the piece to the black player
			_playerBlack._pieces.push_back(move(piece));
		}
	}

	// Go through each piece and calculate all of their legal moves
	setValidMovesOfAllPieces();
}

const Piece* const ChessGame::getPiece(Position position) const
{
	return getPiece(position.getRow(), position.getCol());
}

const Piece* const ChessGame::getPiece(int row, int col) const
{
	// If row and col is inside the board (fail-safe)
	if (row >= 0 && row < BOARD_SIZE &&
		col >= 0 && col < BOARD_SIZE)
		return _board[row][col];
	else
		return nullptr;
}

bool ChessGame::movePiece(Position source, Position destination)
{
	// Get piece in the source position
	Piece* piece = _board[source.getRow()][source.getCol()];

	// If there's no piece in that position, don't make a move.
	if (piece == nullptr)
		return false;

	// If the destination position is not in the piece's list of legal moves
	if (piece->_moves.find(destination) == piece->_moves.end())
		return false;


	// Move the piece
	applyMove(source, destination);

	switchTurns();

	// Go through each piece and calculate all of their legal moves
	setValidMovesOfAllPieces();

	return true;
}

Color ChessGame::getCurrentPlayerColor()
{
	return _playerPlaying->_color;
}

void ChessGame::applyMove(Position source, Position destination)
{
	// Get piece on the source position
	Piece* piece = _board[source.getRow()][source.getCol()];

	// Lift the piece from it's source position
	_board[source.getRow()][source.getCol()] = nullptr;

	// Change the piece's position to the destination
	piece->_position.set(destination);  
	
	// Get the piece from the board in the destination position
	Piece* pieceOnDestination = _board[destination.getRow()][destination.getCol()];

	// If there is a piece in the destination, he's dead
	if (pieceOnDestination != nullptr)
		pieceOnDestination->_isAlive = false;

	// Finally place the piece in the destination
	_board[destination.getRow()][destination.getCol()] = piece;
}

bool ChessGame::moveKeepsKingSafe(Position source, Position destination)
{
	// Create copy of the board
	ChessGame gameCopy = *this;

	// Make the move
	gameCopy.applyMove(source, destination);

	// Go through each piece of the player who's waiting
	for (auto& piece : gameCopy._playerWaiting->_pieces)
	{
		// Calculate the possible moves of that piece
		piece->calculatePossibleMoves(gameCopy._board);

		// If the piece can capture the king, it's an illegal move
		if (piece->_moves.find(gameCopy._playerPlaying->_king->_position) != piece->_moves.end())
			return false;
	}

	// If none of the pieces can capture the king, then it's a legal move
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
	// The player who's waiting cannot move any pieces
	for (unique_ptr<Piece>& piece : _playerWaiting->_pieces)
		piece->_moves.clear();

	// Calculate all legal moves for each piece of the one who's playing
	for (unique_ptr<Piece>& piece : _playerPlaying->_pieces)
		setValidMovesOfPiece(*piece);
}

void ChessGame::setValidMovesOfPiece(Piece& piece)
{
	// Let the piece tell us which moves he can do
	piece.calculatePossibleMoves(_board);

	// Then verify each move, one by one,
	// to check if the king will stay safe after the move
	for (auto itr = piece._moves.begin();itr != piece._moves.end();)
	{
		// Erasing the move will invalidate the iterator,
		// So we increment it right after getting the move
		auto move = *(itr++);

		// If the move does not keep the king safe
		if (!moveKeepsKingSafe(piece._position, move))
			piece._moves.erase(move);
	}
}

// Debugging inside console
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
