#include "SelectModeWindow.h"
#pragma warning(push, 0) 
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#pragma pop()

SelectModeWindow::SelectModeWindow(QWidget* parent) :
	QMainWindow(parent)
{
	auto principalWidget = new QWidget(this);
	auto principalLayout = new QVBoxLayout(principalWidget);

	auto layout = new QHBoxLayout();
	principalLayout->addLayout(layout);
	showCombobox->addItem("Select Mode");
	showCombobox->addItem("Classic");
	showCombobox->addItem("Random");
	showCombobox->addItem("Pawns Behind");
	showCombobox->addItem("Rooks Centered");
	showCombobox->addItem("Three Levels");

	connect(showCombobox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SelectModeWindow::hello);

	layout->addWidget(showCombobox);

	setCentralWidget(principalWidget);
	setWindowTitle("Select Mode Page");

}
void SelectModeWindow::hello()
{
	currentIndex_ = showCombobox->currentIndex();

	switch(currentIndex_)
	{
	case 1:
		chessWindow_._chessUI->chess->setupBoard(new GameModel::BoardSetupClassic());
		chessWindow_.showMaximized();
		this->close();
		break;
	case 2 :
		chessWindow_._chessUI->chess->setupBoard(new GameModel::BoardSetupRandom());
		chessWindow_.showMaximized();
		this->close();
		break;
	case 3:
		chessWindow_._chessUI->chess->setupBoard(new GameModel::BoardSetupPawnsBehind());
		chessWindow_.showMaximized();
		this->close();
		break;
	case 4:
		chessWindow_._chessUI->chess->setupBoard(new GameModel::BoardSetupRooksCentered());
		chessWindow_.showMaximized();
		this->close();
		break;
	case 5:
		chessWindow_._chessUI->chess->setupBoard(new GameModel::BoardSetupOn3Levels());
		chessWindow_.showMaximized();
		this->close();
		break;
	default:
		break;
	}
	

}
