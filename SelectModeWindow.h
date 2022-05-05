#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QString>
#include <QLabel>
#pragma warning(push, 0)

#include "ChessWindow.hpp"
class SelectModeWindow : public QMainWindow {

	Q_OBJECT
public:
	SelectModeWindow(QWidget* parent = nullptr);
	~SelectModeWindow() override = default;

public slots:
	void hello();
private:
	QComboBox* showCombobox = new QComboBox(this);
	ChessWindow chessWindow_;
	int currentIndex_;
	//template <typename T = decltype(nullptr)>
	//QComboBox* newButton(const QString& text, const T& slot = nullptr);

};