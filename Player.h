/* Project : Chess Game Project INF1015
*  File : Player.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe permet de définir les joueurs par leur
*					couleur et les pièces.
*/

#pragma once
#include "Piece.h"
#include "Color.h"
#include <vector>
#include <memory>
#include <list>

namespace GameModel
{
	class Player
	{
	public:
		//! Constructor of a player.
		//! Must specify a color.
		/*!
			\param color the color of the player.
		*/
		Player(Color color) : _color(color), _pieces(), _king(nullptr) {
			_pieces.clear();
		}

		//! Overload of the = operator.
		//! Can be used to copy a player.
		/*!
			\param autre player to copy.
			\returns clone of the player
		*/
		Player& operator=(const Player& autre);
		Player(const Player& autre);

		//! Obtains de piece that the player owns.
		/*!
			\returns a list of pieces
		*/
		const std::list<std::unique_ptr<Piece>>& getPieces() const { return _pieces; }

		//! Gives a piece to the player.
		//! The player will now own the piece.
		/*!
			\param piece piece to give
		*/
		void addPiece(Piece* piece);

	private:
		friend class ChessGame;

		int kingCount = 0;							/**< Number of kings that the player owns */
		Color	_color;								/**< Color of the player */ 
		std::list<std::unique_ptr<Piece>> _pieces;	/**< List of owned pieces */
		Piece* _king;								/**< Pointer to the player's king */
	};
}