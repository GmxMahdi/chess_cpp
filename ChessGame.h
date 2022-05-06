/* Project : Chess Game Project INF1015
*  File : ChessGame.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe permet de gérer le jeux en déterminant les 
*					déplacements valide entre les pièces, et en définissant
*					l'état du jeux et les tours de jeux.
*/

#pragma once
#include "Player.h"
#include "Piece.h"
#include "BoardSetup.h"
#include "DisposableMove.h"

namespace GameModel
{
	class ChessGame
	{
	public:

		//! Enumerates the state of a game.
		enum class State
		{
			PLAYING,    /**< Game is in progress */
			CHECK,		/**< Game is in progress and a king is in check */
			CHECKMATE,  /**< Game has ended and a player has won */
			DRAW		/**< Game has ended and nobody won */
		};

		//! Create instances of a white player and a black player
		//! along with an empty board.
		ChessGame() :
			_playerWhite(Color::WHITE), _playerBlack(Color::BLACK),
			_playerPlaying(nullptr), _playerWaiting(nullptr),
			_state(State::PLAYING)
		{

			for (int i = 0; i < BOARD_SIZE; ++i)
				for (int j = 0; j < BOARD_SIZE; ++j)
					_board[i][j] = nullptr;
		}

	public:
		//! Overload the = operator to copy a chess game.
		ChessGame& operator=(const ChessGame& autre);
		ChessGame(const ChessGame& autre);

		//! Assign the pieces to each player
		//! and place their pieces on the board
		/*!
			The setup could possibly generate errors.
			The errors can be fetched by using getErrorMessages().

			\param setup board setup which contains the pieces to be used.
		*/
		void setupBoard(BoardSetup* setup);

		//! Moves a piece to another location of the board
		/*!
			\param source the position of the piece to move.
			\param destination the position of the piece to move to.
			\returns a boolean wether the move was legal (true) or illegal (false).
		*/
		bool movePiece(Position source, Position destination);

		//! Show the state of the board on the console.
		//! Used for debugging.
		void printBoard();

		//! Gets a piece from the board.
		/*!
			\param position position in the board.
			\returns a pointer to a piece. Is nullptr if there is no piece.
		*/
		const Piece* const	getPiece(Position position) const;

		//! Gets a piece from the board.
		/*!
			\param row position in the board.
			\param col position in the board.
			\returns a pointer to a piece. Is nullptr if there is no piece.
		*/
		const Piece* const	getPiece(int row, int col) const;

		//! Gets the color of the player who's playing.
		Color				getCurrentPlayerColor();

		//! Gets the current state of the game.
		State				getGameState();

		//! Gets the king position of the player who's playing.
		Position			getCurrentPlayerKingPosition();

		
		//! The stored error messages are cleared once
		//! the function is called.
		std::string			getErrorMessages();


	private:
		//! Assigns legal moves to each piece of the player who's playing.
		void setValidMovesOfAllPieces();

		//! Assigns legal moves to a piece.
		void setValidMovesOfPiece(Piece& piece);

		//! Apply a move without any further verifications.
		void applyMove(Position source, Position destination);

		//! Verify wether a move will not put it's own king in check.
		/*!
			\param source position
			\param destination position
			\returns a boolean wether the king is safe or not.
		*/
		bool moveKeepsKingSafe(Position source, Position destination);

		//! Switch the turn between the white player and the black player.
		void switchTurns();

		//! Changes the game state of the game 
		//! if a king is in check or the game has ended.
		void updateGameState();

		//! Checks if the playing player's king is in check
		bool isKingInCheck();

		//! Checks if the playing player has no move (draw)
		bool hasNoLegalMoves();

	private:
		State _state;	/**< State of the game */

		static const int BOARD_SIZE = 8; /**< Board size */
		Piece* _board[BOARD_SIZE][BOARD_SIZE]; /**< Array of pointers to pieces */

		Player _playerWhite{ Color::WHITE };	/**< White player */
		Player _playerBlack{ Color::BLACK };	/**< Black player */

		Player* _playerPlaying;					/**< Pointer to the playing player */
		Player* _playerWaiting;					/**< Pointer to the waiting player */

		std::string _errorMessages = "";		/**< Error messages */
	};
}