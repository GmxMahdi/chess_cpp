#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QMessageBox>
#include <QPainter>
#pragma pop()
#include "Color.h"
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

// This class is literally used just 
// to display a black or white square.
class PlayerIcon : public QWidget {
	Q_OBJECT
public:
	PlayerIcon() : QWidget()
	{
		setFixedSize(ICON_SIZE, ICON_SIZE);
	};

	void setColor(GameModel::Color color);
	void paintEvent(QPaintEvent* event) override;
private:
	static const int ICON_SIZE = 40;
	GameModel::Color _color;
};
