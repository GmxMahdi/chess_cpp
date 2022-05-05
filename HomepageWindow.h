#include "SelectModeWindow.h"
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#pragma warning(push, 0)

class HomepageWindow : public QMainWindow {

	Q_OBJECT
public:
	HomepageWindow(QWidget* parent = nullptr);
	~HomepageWindow() override = default;

public slots:
	void startGame();

private:
	template <typename T = decltype(nullptr)>
	QPushButton* newButton(const QString& text, const T& slot = nullptr);

	SelectModeWindow selectModeWindow_;

};