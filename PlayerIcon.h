/* Project : Chess Game Project INF1015
*  File : PlayerIcon.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe présente l'affichage des icônes de jeux.
*/

#pragma once
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

	//! Constructs the player icon 
	//! based on a fixed size.
	PlayerIcon() : QWidget()
	{
		setFixedSize(ICON_SIZE, ICON_SIZE);
	};

	//! Sets the color of the player who's playing
	void setColor(GameModel::Color color);

	//! Overrides the paint event.
	//! Draws the icon of the player who's playing
	void paintEvent(QPaintEvent* event) override;
private:
	static const int ICON_SIZE = 60; /**< Size of the icon */
	GameModel::Color _color;	/**< Color of the player */
};
