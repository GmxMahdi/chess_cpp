#pragma once

#include "PlayerIcon.h"
#include "ChessUI.h"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#pragma pop()

class ChessWindow : public QMainWindow {
	Q_OBJECT

public:
	ChessWindow(QWidget* parent = nullptr);
	~ChessWindow() override = default;

public slots:
	void updateChessGameInformation();

private:
	ChessUI* _chessUI;
	PlayerIcon* _playerIcon;
	QLabel* _playerLabel;
};
