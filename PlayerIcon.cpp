#include "PlayerIcon.h"

void PlayerIcon::setColor(Color color)
{
	_color = color;
	repaint();
}

void PlayerIcon::paintEvent(QPaintEvent* event)
{
	const int PEN_WIDTH = 3;
	auto painter = QPainter(this);

	auto pen = QPen(Qt::white);
	pen.setWidth(PEN_WIDTH);
	switch (_color)
	{
		case Color::WHITE:
			pen.setColor(Qt::black);
			painter.setBrush(Qt::white);
		break;

		case Color::BLACK:
			pen.setColor(Qt::white);
			painter.setBrush(Qt::black);
		break;
	}
	painter.setPen(pen);
	painter.drawRect(0, 0, ICON_SIZE -1, ICON_SIZE-1);
}
