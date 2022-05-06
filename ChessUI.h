/* Project : Chess Game Project INF1015
*  File : ChessUI.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe représente l'affichage de l'échéquier. 
*/

#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QBrush>
#include <QLabel>
#include <QMessageBox>
#pragma pop()
#include <functional>
#include "ChessGame.h"
#include "Position.h"
#include "BoardSetupClassic.h"
#include "BoardSetupRandom.h"
#include "BoardSetupPawnsBehind.h"
#include "BoardSetupRooksCentered.h"
#include "BoardSetupQueenMarathon.h"


using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .


namespace  GameView
{
	class ChessUI : public QWidget {
		Q_OBJECT
	public:
		ChessUI();

	public:
		//! Overrides the paint event.
		//! Draws the board along with the pieces
		void paintEvent(QPaintEvent* event) override;

		//! Makes a completely new chess game.
		void resetGame();

		//! Gets the color of the player who's currently playing.
		GameModel::Color getCurrentPlayerColor() { return chess->getCurrentPlayerColor(); }
		
		//! Model of the game.
		unique_ptr<GameModel::ChessGame> chess;
	signals:
		//! Advise other UIs if the game's state has changed.
		void gameStateChanged();

	private:
		//! Enumerate of states of the mouse on the board.
		enum class MouseState
		{
			HOVERING,		/**< Mouse is just moving around */// 
			HOLDING_PIECE   /**< Mouse is holding left click + is lifting a piece  */// 
		};

		//! Draw the checkers pattern.
		void drawBoard();

		//! Draw in red the cell of a king in danger (if it applies).
		void drawCellInDanger();

		//! Draw the pieces on the board.
		void drawPieces();

		//! Draw the piece that we are holding with our mouse.
		void drawHoveringPiece();

		//! Hide the piece that was previously drawn on the board
		//! if we're holding it with our mouse.
		void drawHidePiece();

		//! Draw in green the cells that the selected piece can move
		//! and in red those he can capture.
		void drawAvailableMoves();

		//! Highlight in blue the piece that is below our cursor.
		void drawHighlighPiece();

		//! Draw game over symbol on the cell of the king
		//! if the game has ended.
		void drawGameOverCross();

		//! Gets the width of a cell
		int			getCellWidth();

		//! Gets the row and column of the cell below our cursor.
		GameModel::Position	calculateCellPositionFromMouse(QPoint point);

		//! Gets coordinates used to center the piece we're holding onto
		//! on the center of our cursor.
		QPoint		calculateHoveringPiecePositionFromMouse(QPoint point);

	protected:
		//! Overrides the mouseMove event.
		//! Calculates which cell our cursor is above of.
		//! Recalculates hovering piece coordinates
		void mouseMoveEvent(QMouseEvent* event) override;

		//! Overrides the mousePress event.
		//! Checks if our cursor is placed ontop of a piece.
		//! Holds the piece on our cursor if we can move it.
		void mousePressEvent(QMouseEvent* event) override;

		//! Overrides the mouseRelease event.
		//! Attempts to move the piece we're moving on the destination cell.
		void mouseReleaseEvent(QMouseEvent* event) override;

	private:
		
		MouseState mouseState = MouseState::HOVERING;	/**< Mouse state */

		QPoint liftedPiecePosition{ 0,0 };	/**< Coordinates to draw the hovering piece */
		const GameModel::Piece* liftedPiece; /**< Pointer to the lifted piece */

		// Store starting and ending position of the piece
		// that the user lifted.
		GameModel::Position startingPosition; /**< Source pos of the piece 
													right after clicking on one */
		GameModel::Position endingPosition; /**< Destination pos of the piece 
													right after releasing left mouse button */

	};
}
