#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QHash>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include "ui_TestQtGuiApplication.h"
#include "ui_MainWindow.h"

//extern TQANewWindow *new_window;

class TestQtGuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	TestQtGuiApplication(QWidget* parent = Q_NULLPTR);
	Ui::TestQtGuiApplicationClass ui;

public slots:
	void on_lineEditac_returnPressed();
	void on_lineEditpw_returnPressed();
	void on_pushButtonlg_clicked();
	void on_pushButtonex_clicked();
	void on_actionabout_triggered();
};

class TQANewWindow :public QMainWindow
{
	Q_OBJECT

public:
	TQANewWindow(QWidget* parent = Q_NULLPTR);
	Ui::MainWindow nui;
public slots:
	void on_pushButtonbk_clicked();
	void on_pushButtonex_clicked();
	void on_actionabout_triggered();
	void on_pushButtont1_clicked();
	void on_pushButtont2_clicked();
protected:
	void mousePressEvent(QMouseEvent* qme);
	void mouseMoveEvent(QMouseEvent* qme);
	void mouseReleaseEvent(QMouseEvent* qme);
	void wheelEvent(QWheelEvent* qwe);
};


