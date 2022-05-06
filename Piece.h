/* Project : Chess Game Project INF1015
*  File : Piece.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	Cette classe est une classe abstraite qui est la base de
*					toutes les classes qui définissent des types de pièces. 
				    Ces classes servent à définir les déplacement des pièces.
*/

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
		//! Constructs a piece. Defaults to white.
		Piece() : _color(Color::WHITE), _position() {}

		//! Constructor of a piece.
		/*!
			\param color the color of the piece.
			\param position the position of the piece of the board.
		*/
		Piece(Color color, Position position) : _color(color), _position(position) {}

		//! Destroys piece.
		virtual ~Piece() = default;

		//! Gets an ASCII representation of a piece to be shown on console.
		std::string		getAscii() const;

		//! Gets the color of the piece.
		Color			getColor() const;

		//! Gets the position of the piece.
		Position		getPosition() const;

		//! Returns the list of possible moves for that piece.
		std::unordered_set<Position> getPossibleMoves() const;

		//! Gets the file name of an image of the piece.
		virtual std::string getImageName() const = 0;

		//! Create a copy of the piece.
		virtual std::unique_ptr<Piece> clone() const = 0;


	protected:

		//! Char representation of a piece.
		virtual char  getSymbol() const = 0;

		//! Check if a piece is the same color of another piece.
		bool hasSameColorOfOtherPiece(Piece* piece);

		//! Check if the piece is of opposite color or is null.
		bool canStepOnPiece(Piece* piece);

		//! Adds the move to its move list if the piece can be placed on the position.
		bool addMoveIfPossible(Piece* board[8][8], Position move);

		//! Calculates the possibles moves the piece can do on the board.
		//! Fills it's move list with the avaiable positions.
		/*!
			\param board chess board in which the piece is placed in.
		*/
		virtual void calculatePossibleMoves(Piece* board[8][8]) = 0;

	protected:
		Color		_color;						/**< Color of the piece */
		Position	_position;					/**< Position of the piece */
		std::unordered_set<Position> _moves;	/**< List of possible moves */
		bool		_isAlive = true;			/**< If the piece is on the board */


	private:
		friend class DisposableMove;
		friend class ChessGame;
	};
}