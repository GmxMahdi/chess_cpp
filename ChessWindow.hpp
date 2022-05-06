/* Project : Chess Game Project INF1015
*  File : ChessWindow.hpp
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe regroupe l'affichage de l'échéquier
					et du menu du jeux.
*/

#pragma once

#include "PlayerIcon.h"
#include "ChessUI.h"
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
	//! Constructs the main UI of the chess window.
	ChessWindow(QWidget* parent = nullptr);

	//! Deconstructs the main UI of the chess window.
	~ChessWindow() override = default;

	//! Closes the window.
	void quitGame();

	//! Resets the game.
	void restartGame();

	//! Start a new game.
	void startGame();
public slots:
	//! Update UI components when the state of the game changed.
	void updateChessGameInformation();

public:
	GameView::ChessUI* _chessUI; /**< Ref to the main visuals of the chessboard. */
private:
	QPushButton* _startButton = new QPushButton(this);		/**< Start Button */
	QPushButton* _restartButton = new QPushButton(this);	/**< Restart Button */

	vector<function<void()>> _boardSetups;				/**< Lambda BoardSetups */
	QComboBox* _boardSetupsComboBox = new QComboBox(this);	/**< ComboBox of board setups */
	PlayerIcon* _playerIcon;		/**< Player icon */
	QLabel* _playerLabel;			/**< Player label */
};
