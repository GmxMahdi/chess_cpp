#pragma once
// Le Mod�le pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
#include <QObject>
#include <QMessageBox>
#include <QPainter>
#pragma pop()
#include "Color.h"
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class PlayerIcon : public QWidget {
	Q_OBJECT
public:
	PlayerIcon() : QWidget()
	{
		setFixedSize(ICON_SIZE, ICON_SIZE);
	};

	void setColor(Color color);
	void paintEvent(QPaintEvent* event) override;
private:
	static const int ICON_SIZE = 40;
	Color _color;
};
