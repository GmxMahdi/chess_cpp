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

	QComboBox* showCombobox = new QComboBox(this);
	showCombobox->addItem("Select Mode");
	showCombobox->addItem("Classic Mode");
	showCombobox->addItem("Random Mode");

	layout->addWidget(showCombobox);

	setCentralWidget(principalWidget);
	setWindowTitle("Select Mode Page");

}

void SelectModeWindow::open()
{
	this->show();
}