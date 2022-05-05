#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QString>
#include <QLabel>
#pragma warning(push, 0)


class SelectModeWindow : public QMainWindow {

	Q_OBJECT
public:
	SelectModeWindow(QWidget* parent = nullptr);
	~SelectModeWindow() override = default;

	void open();
public slots:
	
private:
	
	//template <typename T = decltype(nullptr)>
	//QComboBox* newButton(const QString& text, const T& slot = nullptr);

};