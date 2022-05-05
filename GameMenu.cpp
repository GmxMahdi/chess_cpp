//#include "GameMenu.h"
//
//#pragma warning(push, 0) 
//#include <QPushButton>
//#include <QLabel>
//#include <QHBoxLayout>
//#include <QString>
//#pragma pop()
//
//template <typename T>
//QPushButton* GameMenu::newButton(const QString& text, const T& slot)
//{
//	auto button = new QPushButton(this);
//	button->setText(text);
//	button->setFixedSize(150, 40);
//	return button;
//}
//
//GameMenu::GameMenu(QWidget* parent) :
//	QMainWindow(parent)
//{
//	//auto principalWidget = new QWidget(this);
//	//auto principalLayout = new QVBoxLayout(principalWidget);
//
//	//auto layout = new QHBoxLayout();
//	//principalLayout->addLayout(layout);
//
//	restartButton_ = newButton(QString::asprintf("Restart Game"));
//	QObject::connect(restartButton_, &QPushButton::clicked, this, &GameMenu::restartGame);
//
//	quitButton_ = newButton(QString::asprintf("Quit Game"));
//	QObject::connect(quitButton_, &QPushButton::clicked, this, &ChessWindow::quitGame);
//	//layout->addWidget(button);
//
//	//setCentralWidget(principalWidget);
//	//setWindowTitle("Chess Game Homepage");
//}
//
//void GameMenu::restartGame() 
//{
//	selectModeWindow_.open();
//	this->hide();
//}
//
//void GameMenu::quitGame() 
//{
//	this->close();
//}