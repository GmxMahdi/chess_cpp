#pragma once

#include "PlayerIcon.h"
#include "ChessUI.h"
//#include "SelectModeWindow.h"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QComboBox>
#pragma pop()

class ChessWindow : public QMainWindow 
{
	Q_OBJECT

public:
	ChessWindow(QWidget* parent = nullptr);
	~ChessWindow() override = default;
	GameView::ChessUI* _chessUI;
	void quitGame();
	void restartGame();
	void startGame();
public slots:
	void updateChessGameInformation();

private:
	QPushButton* _startBtn = new QPushButton(this);
	QPushButton* _restartBtn = new QPushButton(this);

	vector<function<void()>> _boardSetups;
	QComboBox* _cbBoardSetups = new QComboBox(this);
	PlayerIcon* _playerIcon;
	QLabel* _playerLabel;

	//SelectModeWindow selectModeWindow_;
};
