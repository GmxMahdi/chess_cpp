#include "ChessUI.h"
#include <iostream>
#include <string>

using namespace std;
using namespace GameModel;
using namespace GameView;
// When the mouse moves anywhere and anytime on the board, 
// this function is called

ChessUI::ChessUI() : QWidget() {
	setMouseTracking(true);
	setFixedSize(500, 500);


	//chess->setupBoard(new GameModel::BoardSetupPawnsBehind());
	chess = make_unique<ChessGame>();

	std::string errors = chess->getErrorMessages();
	if (errors != "")
		QMessageBox::warning(
			this,
			tr("Game Setup Error"),
			tr(errors.c_str()));
};

void ChessUI::mouseMoveEvent(QMouseEvent* mouseEvent)
{
	if (mouseState == MouseState::HOVERING)
	{
		// Get the cell position from the mouse's coordinates
		Position pos = calculateCellPositionFromMouse(mouseEvent->pos());

		// Get the piece the mouse is hovering on.
		liftedPiece = chess->getPiece(pos);
	}

	// When we will actualy lift the piece, center it on the mouse's cursor
	liftedPiecePosition = calculateHoveringPiecePositionFromMouse(mouseEvent->pos());

	// Force QObject to be repainted
	repaint();
}

void ChessUI::mousePressEvent(QMouseEvent* event)
{
	// Get the cell position from the mouse's coordinates
	Position pos = calculateCellPositionFromMouse(event->pos());
	cout << "(" << pos.getRow() << ", " << pos.getCol() << ")\n";

	// Get the cell position from the mouse's coordinates
	const Piece* piece = chess->getPiece(pos);

	// If there is a piece in that cell
	// and if it's the color of the player who's playing
	if (piece != nullptr &&
		piece->getColor() == chess->getCurrentPlayerColor())
	{
		liftedPiece = piece;
		startingPosition = pos;

		// Player is now holding a piece of his cursor
		mouseState = MouseState::HOLDING_PIECE;
	}

	// Force repaint
	repaint();
}

void ChessUI::mouseReleaseEvent(QMouseEvent* event)
{
	// Get the cell position from the mouse's coordinates
	Position pos = calculateCellPositionFromMouse(event->pos());

	// If mouse was holding a piece, then he want to make a move
	if (mouseState == MouseState::HOLDING_PIECE)
	{
		// Ending position of the move
		endingPosition = pos;

		// Attempt to move the piece
		bool moved = chess->movePiece(startingPosition, endingPosition);

		// If the move was a success
		if (moved)
		{
			if (chess->getGameState() == ChessGame::State::CHECK)
				cout << "CHECK!!!\n";

			cout << "ChessUI: Piece was moved\n";
			emit gameStateChanged(); // To make adjutement on the UI (outside of the board)
		}
		else
			cout << "ChessUI: Move is illegal.\n";
	}

	// Go back to just hovering
	mouseState = MouseState::HOVERING;

	liftedPiece = nullptr;

	// Force repaint
	repaint();
}


// Cell width is relative to the QWidget's size
// (maybe could have stored a value instead)
int  ChessUI::getCellWidth()
{
	return this->rect().width() / 8;
}

// Get (row, col) from mouse coordinates
Position ChessUI::calculateCellPositionFromMouse(QPoint point)
{
	int width = getCellWidth();
	return { point.y() / width, point.x() / width };
}

// Calculate (x, y) to draw the lifted piece on the center of the mouse's cursor
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


// This function is called when the app thinks it needs
// the drawing to be refreshed.
// We can also force it by calling repaint()
void ChessUI::paintEvent(QPaintEvent* event)
{
	drawBoard();
	drawCellInDanger();
	drawAvailableMoves();
	drawHighlighPiece();
	drawPieces();
	drawHoveringPiece();
	drawGameOverCross();
}

void GameView::ChessUI::resetGame()
{
	chess = make_unique<ChessGame>();
	this->repaint();
}

void ChessUI::drawBoard()
{
	QBrush brushes[2] = {Qt::gray, Qt::white};
	int width = getCellWidth();
	auto painter = QPainter(this);

	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			painter.setBrush(brushes[(row + col) % 2]);
			painter.drawRect(row * width, col * width, width, width);
		}
}

void ChessUI::drawCellInDanger()
{
	if (chess->getGameState() == ChessGame::State::CHECK)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		painter.setBrush(Qt::red);

		Position dangerPos = chess->getCurrentPlayerKingPosition();
		painter.drawRect(
			dangerPos.getCol() * width,
			dangerPos.getRow() * width,
			width, 
			width);
	}
}
void ChessUI::drawPieces()
{
	int width = getCellWidth();
	auto painter = QPainter(this);

	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			auto piece = chess->getPiece(row, col);
			if (piece != nullptr)
			{
				string fileUrl = ":/res/pieces/" + piece->getImageName();
				QPixmap image(fileUrl.c_str());
				painter.drawPixmap(col * width, row * width, width, width, image);
			}
		}
	drawHidePiece(); // Hide the one that we are holding (if we're holding one)
}

// That's the lifted piece
void ChessUI::drawHoveringPiece()
{
	if (mouseState == MouseState::HOLDING_PIECE)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		string fileUrl(":/res/pieces/"s +liftedPiece->getImageName());
		QPixmap image(fileUrl.c_str());
		painter.drawPixmap(liftedPiecePosition.x(), liftedPiecePosition.y(), width, width, image);
	}
}

// If we're lifting a piece, hide the one we drew on the board
void ChessUI::drawHidePiece()
{
	if (mouseState == MouseState::HOLDING_PIECE)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		Position pos = liftedPiece->getPosition();
		QBrush brushes[2] = { Qt::gray, Qt::white };
		painter.setBrush(brushes[(pos.getRow() + pos.getCol()) % 2]);
		painter.drawRect(pos.getCol() * width, pos.getRow() * width, width, width);
	}
}

void ChessUI::drawAvailableMoves()
{
	if (liftedPiece != nullptr)
	{
		int width = getCellWidth();

		auto moves = liftedPiece->getPossibleMoves();
		auto painter = QPainter(this);
		
		painter.setCompositionMode(QPainter::CompositionMode::CompositionMode_SourceOver);
		painter.setOpacity(0.50);
		for (auto&& move : moves)
		{
			if (chess->getPiece(move) != nullptr)
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

// Add a little bright light to the piece below our mouse's cursor.
void ChessUI::drawHighlighPiece()
{
	if (mouseState == MouseState::HOVERING &&
		liftedPiece != nullptr &&
		liftedPiece->getColor() ==  chess->getCurrentPlayerColor())
	{
		int width = getCellWidth();
		auto painter = QPainter(this);

		QColor blue = Qt::blue;
		blue.setAlphaF(0.3);
		painter.setBrush(blue);
		painter.setCompositionMode(QPainter::CompositionMode::CompositionMode_SourceOver);

		painter.drawRect(
			liftedPiece->getPosition().getCol() * width, 
			liftedPiece->getPosition().getRow() * width,
			width, width);

	}
}

void ChessUI::drawGameOverCross()
{
	if (chess->getGameState() == ChessGame::State::CHECKMATE)
	{
		int width = getCellWidth();
		auto painter = QPainter(this);
		painter.setBrush(Qt::red);

		Position dangerPos = chess->getCurrentPlayerKingPosition();
		QPixmap deadImage(":/res/pieces/dead.png");
		painter.drawPixmap(
			dangerPos.getCol() * width,
			dangerPos.getRow() * width,
			width,
			width,
			deadImage);
	}
}
