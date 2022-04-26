#pragma once
#include <unordered_set>
#include <memory>
#include <string>
#include "Color.h"
#include "Position.h"

namespace GameModel
{
	class Piece
	{
	public:
		Piece() : _color(Color::WHITE), _position() {}
		Piece(Color color, Position position) : _color(color), _position(position) {}

		virtual ~Piece() = default;

		std::string		getAscii() const;
		Color			getColor() const;
		Position		getPosition() const;

		std::unordered_set<Position> getPossibleMoves() const;
		virtual std::string getImageName() const = 0;

		virtual std::unique_ptr<Piece> clone() const = 0;


	protected:

		// Char representation of a piece
		virtual char  getSymbol() const = 0;

		bool hasSameColorOfOtherPiece(Piece* piece);
		bool canStepOnPiece(Piece* piece);
		bool addMoveIfPossible(Piece* board[8][8], Position move);

	protected:
		Color		_color;
		Position	_position;
		std::unordered_set<Position> _moves;
		bool		_isAlive = true;


	private:
		friend class DisposableMove;
		friend class ChessGame;
	protected:
		virtual void calculatePossibleMoves(Piece* board[8][8]) = 0;
	};
}