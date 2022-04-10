#include "ChessUI.h"
#include <iostream>
#include <string>

using namespace std;

void ChessUI::mouseMoveEvent(QMouseEvent* mouseEvent)
{
	if (mouseState == MouseState::HOVERING)
	{
		Position pos = calculateCellPositionFromMouse(mouseEvent->pos());
		holdingPiece = chess.getPiece(pos);
	}

	piecePoint = calculateHoveringPiecePositionFromMouse(mouseEvent->pos());
	repaint();
}

void ChessUI::mousePressEvent(QMouseEvent* event)
{

	Position pos = calculateCellPositionFromMouse(event->pos());
	cout << "(" << pos.getRow() << ", " << pos.getCol() << ")\n";

	const Piece* piece = chess.getPiece(pos);
	if (piece != nullptr &&
		piece->getColor() == chess.getCurrentPlayerColor())
	{
		holdingPiece = piece;
		startingPosition = pos;
		mouseState = MouseState::HOLDING;
	}

	repaint();
}

void ChessUI::mouseReleaseEvent(QMouseEvent* event)
{
	Position pos = calculateCellPositionFromMouse(event->pos());
	if (mouseState == MouseState::HOLDING)
	{
		endingPosition = pos;
		bool moved = chess.movePiece(startingPosition, endingPosition);
		if (moved)
		{
			cout << "ChessUI: Piece was moved\n";
			emit gameStateChanged();
		}
		else
			cout << "ChessUI: Move is illegal.\n";
	}

	mouseState = MouseState::HOVERING;
	holdingPiece = nullptr;
	repaint();
}

int  ChessUI::getCellWidth()
{
	return this->rect().width() / 8;
}

Position ChessUI::calculateCellPositionFromMouse(QPoint point)
{
	int width = getCellWidth();
	return { point.y() / width, point.x() / width };
}

QPoint ChessUI::calculateHoveringPiecePositionFromMouse(QPoint point)
{

	int width = getCellWidth();
	int halfWidth = width /2;
	int x = point.x() - halfWidth;
	int y = point.y() - halfWidth;

	if (x < 0) x = 0;
	if (y < 0) y = 0;

	int boardWidth = this->rect().width();
	if (x + width > boardWidth)
		x = boardWidth - width;

	if (y + width > boardWidth)
		y = boardWidth - width;
	return QPoint(x, y);
}


void ChessUI::paintEvent(QPaintEvent* event)
{
	drawBoard();
	drawPieces();
	drawHighlighPiece();
	drawAvailableMoves();
	drawHoveringPiece();
}

void ChessUI::drawBoard()
{
	int width = getCellWidth();
	auto painter = QPainter(this);

	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			if ((row + col) % 2 == 1)
				painter.setBrush(Qt::darkBlue);
			else
				painter.setBrush(Qt::gray);
			painter.drawRect(row * width, col * width, width, width);
		}
}

void ChessUI::drawPieces()
{
	int width = getCellWidth();
	auto painter = QPainter(this);

	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			auto piece = chess.getPiece(row, col);
			if (piece != nullptr)
			{
				string fileUrl = ":/res/pieces/" + piece->getImageName();
				QPixmap image(fileUrl.c_str());
				painter.drawPixmap(col * width, row * width, width, width, image);
			}
		}
	drawHidePiece();
}

void ChessUI::drawHoveringPiece()
{
	if (mouseState == MouseState::HOLDING)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		string fileUrl(":/res/pieces/"s +holdingPiece->getImageName());
		QPixmap image(fileUrl.c_str());
		painter.drawPixmap(piecePoint.x(), piecePoint.y(), width, width, image);
	}
}

void ChessUI::drawHidePiece()
{
	if (mouseState == MouseState::HOLDING)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		Position pos = holdingPiece->getPosition();
		if ((pos.getRow() + pos.getCol()) % 2 == 1)
			painter.setBrush(Qt::darkBlue);
		else
			painter.setBrush(Qt::gray);

		painter.drawRect(pos.getCol() * width, pos.getRow() * width, width, width);
	}
}

void ChessUI::drawAvailableMoves()
{
	if (holdingPiece != nullptr)
	{
		int width = getCellWidth();

		auto moves = holdingPiece->getPossibleMoves();
		auto painter = QPainter(this);
		
		painter.setCompositionMode(QPainter::CompositionMode::CompositionMode_Lighten);

		for (auto&& move : moves)
		{
			if (chess.getPiece(move) != nullptr)
				painter.setBrush(Qt::red);
			else
				painter.setBrush(Qt::green);
			painter.drawRect(
				move.getCol() * width,
				move.getRow() * width,
				width,
				width);
		}
		
	}

}

void ChessUI::drawHighlighPiece()
{
	if (mouseState == MouseState::HOVERING &&
		holdingPiece != nullptr &&
		holdingPiece->getColor() ==  chess.getCurrentPlayerColor())
	{
		int width = getCellWidth();
		auto painter = QPainter(this);

		QColor blue = Qt::blue;
		blue.setAlphaF(0.3);
		painter.setBrush(blue);
		painter.setCompositionMode(QPainter::CompositionMode::CompositionMode_SourceOver);

		painter.drawRect(
			holdingPiece->getPosition().getCol() * width, 
			holdingPiece->getPosition().getRow() * width,
			width, width);

	}
}
