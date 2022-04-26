// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "ChessWindow.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QImage>
#include <QPainter>
#include <QWidget>
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>

#include "ChessUI.h"
#include "PlayerIcon.h"

using iter::range;
using namespace GameModel;
using namespace GameView;
ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{
	// Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.
	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);
	// Donner un parent à un layout est comme un setLayout.

	_playerLabel = new QLabel(this);
	_playerLabel->setText("Turn to play: ");
	_playerLabel->setFont(QFont("", 15, -1));
	_playerIcon = new PlayerIcon();
	_playerIcon->setColor(Color::WHITE);

	auto topWidget = new QWidget(this);
	auto topLayout = new QHBoxLayout(topWidget);
	topLayout->setAlignment(Qt::AlignLeft);



	auto horizontalWidget = new QWidget(this);
	auto horizontalLayout = new QHBoxLayout(horizontalWidget);

	_chessUI = new ChessUI();
	connect(_chessUI, &ChessUI::gameStateChanged, this, &ChessWindow::updateChessGameInformation);


	auto labelsWidget = new QWidget(this);
	auto labelsLayout = new QVBoxLayout(labelsWidget);
	labelsLayout->setAlignment(Qt::AlignTop);

	auto label = new QLabel(this);
	label->setFont(QFont("", 10));
	label->setText("SUS???");

	auto label2 = new QLabel(this);
	label2->setText("SUSU WUSSY???");
	label2->setFont(QFont("", 10));


	layoutPrincipal->addWidget(topWidget);
	layoutPrincipal->addWidget(horizontalWidget);
	topLayout->addWidget(_playerLabel);
	topLayout->addWidget(_playerIcon);
	horizontalLayout->addWidget(_chessUI);
	horizontalLayout->addWidget(labelsWidget);
	labelsLayout->addWidget(label);
	labelsLayout->addWidget(label2);

	setCentralWidget(widgetPrincipal);
	setWindowTitle("Sussy Wussy Chess Game (SUS)");
}

void ChessWindow::updateChessGameInformation()
{
	_playerIcon->setColor(_chessUI->getCurrentPlayerColor());
}
