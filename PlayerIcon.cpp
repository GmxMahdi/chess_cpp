#include "PlayerIcon.h"

using namespace GameModel;

void PlayerIcon::setColor(Color color)
{
	_color = color;
	repaint();
}

void PlayerIcon::paintEvent(QPaintEvent* event)
{
	char whiteKing[] = ":/res/pieces/Chess_klt60.png";
	char blackKing[] = ":/res/pieces/Chess_kdt60.png";

	const int PEN_WIDTH = 3;
	auto painter = QPainter(this);
	auto pen = QPen(Qt::white);
	char* kingColor = nullptr;

	pen.setWidth(PEN_WIDTH);
	switch (_color)
	{
		case Color::WHITE:
			pen.setColor(Qt::white);
			painter.setBrush(Qt::black);
			kingColor = whiteKing;
		break;

		case Color::BLACK:
			pen.setColor(Qt::black);
			painter.setBrush(Qt::white);
			kingColor = blackKing;
		break;
	}
	painter.setPen(pen);
	//painter.drawRect(0, 0, ICON_SIZE -1, ICON_SIZE-1);
	QPixmap image(kingColor);
	painter.drawPixmap(0, 0, ICON_SIZE, ICON_SIZE, image);
}
