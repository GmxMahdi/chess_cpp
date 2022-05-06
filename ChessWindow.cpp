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
	_playerLabel->setFont(QFont(_playerLabel->font().family(), 13, -1));
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


	//// Board Setups
	_boardSetups = {
		[this]() {_chessUI->chess->setupBoard(new BoardSetupClassic()); },
		[this]() {_chessUI->chess->setupBoard(new BoardSetupRandom()); },
		[this]() {_chessUI->chess->setupBoard(new BoardSetupQueenMarathon()); },
		[this]() {_chessUI->chess->setupBoard(new BoardSetupPawnsBehind()); },
		[this]() {_chessUI->chess->setupBoard(new BoardSetupRooksCentered()); },
		
	};

	/////Combobox
	_cbBoardSetups->setFont(QFont(_cbBoardSetups->font().family(), 10));
	_cbBoardSetups->addItem("Classic");
	_cbBoardSetups->addItem("Random");
	_cbBoardSetups->addItem("Queen Marathon");
	_cbBoardSetups->addItem("Pawns Behind");
	_cbBoardSetups->addItem("Rooks Centered");


	////Ajout du bouton start
	_startBtn->setText("Start Game");
	_startBtn->setFont(QFont(_startBtn->font().family(), 10));
	QObject::connect(_startBtn, &QPushButton::clicked, this, &ChessWindow::startGame);



	////Ajout du bouton recommencer la partie
	_restartBtn->setDisabled(true);
	_restartBtn->setText("Restart Game");
	_restartBtn->setFont(QFont(_restartBtn->font().family(), 10));
	QObject::connect(_restartBtn, &QPushButton::clicked, this, &ChessWindow::restartGame);
	_restartBtn->setDisabled(true);

	//////Ajout du bouton quitter la partie
	auto quitButton = new QPushButton(this);
	quitButton->setText("Quit Game");
	quitButton->setFont(QFont(quitButton->font().family(), 10));
	QObject::connect(quitButton, &QPushButton::clicked, this, &ChessWindow::quitGame);

	
	///// Ajout label
	auto boardSetupLabel = new QLabel(this);
	boardSetupLabel->setText("Board Setup");
	boardSetupLabel->setFont(QFont(boardSetupLabel->font().family(), 11));




	
	layoutPrincipal->addWidget(topWidget);
	layoutPrincipal->addWidget(horizontalWidget);
	topLayout->addWidget(_playerLabel);
	topLayout->addWidget(_playerIcon);
	horizontalLayout->addWidget(_chessUI);
	horizontalLayout->addWidget(labelsWidget);
	//labelsLayout->addWidget(label);
	//labelsLayout->addWidget(label2);
	labelsLayout->addWidget(boardSetupLabel);
	labelsLayout->addWidget(_cbBoardSetups);

	labelsLayout->addSpacing(0);
	labelsLayout->addWidget(_startBtn);
	labelsLayout->addSpacing(20);

	labelsLayout->addWidget(_restartBtn);
	labelsLayout->addWidget(quitButton);
	



	setCentralWidget(widgetPrincipal);
	setWindowTitle("Chess Game INF1015");
}

void ChessWindow::updateChessGameInformation()
{
	_playerIcon->setColor(_chessUI->getCurrentPlayerColor());
}

void ChessWindow::startGame()
{
	_startBtn->setDisabled(true);
	_cbBoardSetups->setDisabled(true);
	_restartBtn->setDisabled(false);

	_boardSetups[_cbBoardSetups->currentIndex()]();


	std::string errors = _chessUI->chess->getErrorMessages();
	if (errors != "")
		QMessageBox::warning(
			this,
			tr("Game Setup Error"),
			tr(errors.c_str()));

	updateChessGameInformation();
	_chessUI->repaint();
}

void ChessWindow::quitGame() 
{
	this->close();
}

void ChessWindow::restartGame() 
{
	_chessUI->resetGame();
	_startBtn->setDisabled(false);
	_cbBoardSetups->setDisabled(false);
	_restartBtn->setDisabled(true);

	//selectModeWindow_.open();
}


