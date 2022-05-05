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

	//auto label = new QLabel(this);
	//label->setFont(QFont("", 10));
	//label->setText("Project INF1015");

	//auto label2 = new QLabel(this);
	//label2->setText("Chess Game");
	//label2->setFont(QFont("", 10));

	//Ajout du bouton recommencer la partie
	auto restartButton = new QPushButton(this);
	restartButton->setText("Restart Game");
	restartButton->setFont(QFont("", 10));
	QObject::connect(restartButton, &QPushButton::clicked, this, &ChessWindow::restartGame);

	////Ajout du bouton quitter la partie
	auto quitButton = new QPushButton(this);
	quitButton->setText("Quit Game");
	quitButton->setFont(QFont("", 10));
	QObject::connect(quitButton, &QPushButton::clicked, this, &ChessWindow::quitGame);

	
	
	layoutPrincipal->addWidget(topWidget);
	layoutPrincipal->addWidget(horizontalWidget);
	topLayout->addWidget(_playerLabel);
	topLayout->addWidget(_playerIcon);
	horizontalLayout->addWidget(_chessUI);
	horizontalLayout->addWidget(labelsWidget);
	//labelsLayout->addWidget(label);
	//labelsLayout->addWidget(label2);
	labelsLayout->addWidget(restartButton);
	labelsLayout->addWidget(quitButton);
	//labelsLayout->addWidget(quitButton);

	setCentralWidget(widgetPrincipal);
	setWindowTitle("Chess Game INF1015");
}

void ChessWindow::updateChessGameInformation()
{
	_playerIcon->setColor(_chessUI->getCurrentPlayerColor());
}

void ChessWindow::quitGame() 
{
	this->close();
}

void ChessWindow::restartGame() 
{
	this->quitGame();
	selectModeWindow_.open();
}