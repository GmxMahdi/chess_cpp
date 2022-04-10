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
		HOVERING,
		HOLDING
	};
	void drawBoard();
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

	QPoint piecePoint{ 0,0 };
	const Piece* holdingPiece;
	Position startingPosition;
	Position endingPosition;

};
