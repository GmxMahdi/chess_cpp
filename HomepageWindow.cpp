#include "HomepageWindow.h"

#pragma warning(push, 0) 
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#pragma pop()

template <typename T>
QPushButton* HomepageWindow::newButton(const QString& text, const T& slot) 
{
	auto button = new QPushButton(this);
	button->setText(text);
	button->setFixedSize(150, 40);
	return button;
}

HomepageWindow::HomepageWindow(QWidget* parent) :
	QMainWindow(parent) 
{
	auto principalWidget = new QWidget(this);
	auto principalLayout = new QVBoxLayout(principalWidget);

	auto layout = new QHBoxLayout();
	principalLayout->addLayout(layout);

	auto button = newButton(QString::asprintf("Start Game"));
	QObject::connect(button, &QPushButton::clicked, this, &HomepageWindow::startGame);
	layout->addWidget(button);

	setCentralWidget(principalWidget);
	setWindowTitle("Chess Game Homepage");
}

void HomepageWindow::startGame() 
{
	selectModeWindow_.open();
	this->hide();
}