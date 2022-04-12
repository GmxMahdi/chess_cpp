#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QBrush>
#include <QLabel>
#pragma pop()
#include <functional>
#include "ChessGame.h"
#include "Position.h"
#include "BoardSetupClassic.h"


using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class ChessUI : public QWidget {
	Q_OBJECT
public:
	ChessUI() : QWidget() {
		setMouseTracking(true);
		setFixedSize(500, 500);
		chess.setupBoard(new BoardSetupClassic());
	};

public:
	Color getCurrentPlayerColor() { return chess.getCurrentPlayerColor(); }
	void paintEvent(QPaintEvent* event) override;

signals:
	void gameStateChanged();

private:
	enum class MouseState
	{
		HOVERING,		// Mouse if just moving around
		HOLDING_PIECE   // Mouse is lifting a piece + is holding left click
	};
	void drawBoard();
	void drawCellInDanger();
	void drawPieces();
	void drawHoveringPiece();
	void drawHidePiece();
	void drawAvailableMoves();
	void drawHighlighPiece();

	int			getCellWidth();
	Position	calculateCellPositionFromMouse(QPoint point);
	QPoint		calculateHoveringPiecePositionFromMouse(QPoint point);

protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	ChessGame chess;
	MouseState mouseState = MouseState::HOVERING;

	QPoint liftedPiecePosition{ 0,0 };
	const Piece* liftedPiece;

	// Store starting and ending position of the piece
	// that the user lifted.
	Position startingPosition;
	Position endingPosition;

};
