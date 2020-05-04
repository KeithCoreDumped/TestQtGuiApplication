#include "TestQtGuiApplication.h"
#define ABORT_IMFORMATION u8"<html>\
 <head></head>\
 <body>\
  <p align=\"center\"><span style=\" font-size:12pt;\">实践2 </span><span style=\" font-size:12pt; vertical-align:super;\">Z******* Edition </span><span style=\" font-size:12pt; vertical-align:sub;\">33</span></p>\
  <p align=\"center\">Built With:</p>\
  <p align=\"center\"><a href=\"https://www.qt.io\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">Qt | Cross-platform software development for embedded &amp; desktop</span></a><span style=\" font-size:10pt;\"><br />\
    </span><a href=\"https://visualstudio.microsoft.com/zh-hans/vs/\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">Visual Studio 2019 IDE - 适用于 Windows 的编程软件</span></a></p>\
  <p align=\"center\"><a href=\"https://www.cplusplus.org/\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">C++.org</span></a></p>\
 </body>\
</html>"

TQANewWindow* new_window;
TestQtGuiApplication* ptr2TQA;
bool pressed = 0;
int ox, oy, ow, oh, mx, my, os;
float sc;
QString msg;

TestQtGuiApplication::TestQtGuiApplication(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ptr2TQA = this;
	move(QPoint(QDesktopWidget().width() / 2 - this->width() / 2, QDesktopWidget().height() / 2 - this->height() / 2));
	this->activateWindow();
	this->ui.lineEditac->setFocus();
	//QObject::connect(this->ui.pushButtonlg, SIGNAL(clicked()), this, SLOT(on_pushButtonlg_clicked()));
	//QObject::connect(this->ui.pushButtonex, SIGNAL(clicked()), this, SLOT(on_pushButtonex_clicked()));

}

void TestQtGuiApplication::on_pushButtonlg_clicked()
{
	if ((qHash(this->ui.lineEditac->text(), 2356) == 0x82dcf771) && qHash(this->ui.lineEditpw->text(), 4789) == 0x95926e9f)
	{
		//if (new_window)
			//delete new_window;
		new_window = new TQANewWindow;
		this->setVisible(false);
		new_window->show();
		if (!this->ui.checkBoxrpw->isChecked())
			this->ui.lineEditpw->setText("");
	}
	else {
		QMessageBox::critical(this, tr(u8"错误"), tr(u8"用户名或密码错误！"));
	}
}

void TestQtGuiApplication::on_pushButtonex_clicked()
{
	if (QMessageBox::warning(this, tr(u8"退出"), tr(u8"确定退出？"), QMessageBox::Yes | QMessageBox::Cancel) == QMessageBox::Yes)
	{
		this->close();
	}
}

void TestQtGuiApplication::on_lineEditac_returnPressed()
{
	this->ui.lineEditpw->setFocus();
}

void TestQtGuiApplication::on_lineEditpw_returnPressed()
{
	TestQtGuiApplication::on_pushButtonlg_clicked();
}

void TestQtGuiApplication::on_actionabout_triggered()
{
	QMessageBox::about(this, tr(u8"关于"), tr(ABORT_IMFORMATION));
}

TQANewWindow::TQANewWindow(QWidget* parent) :QMainWindow(parent)
{
	nui.setupUi(this);
	move(QPoint(QDesktopWidget().width() / 2 - this->width() / 2, QDesktopWidget().height() / 2 - this->height() / 2));
	ox = this->nui.labelcr->geometry().x();
	oy = this->nui.labelcr->geometry().y();
	ow = this->nui.labelcr->geometry().width();
	oh = this->nui.labelcr->geometry().height();
	sc = 1.0f;
}

void TQANewWindow::on_pushButtonbk_clicked()
{
	this->setVisible(false);
	this->nui.setupUi(this);
	ptr2TQA->setVisible(true);
}

void TQANewWindow::on_pushButtonex_clicked()
{
	if (QMessageBox::warning(this, tr(u8"退出"), tr(u8"确定退出？"), QMessageBox::Yes | QMessageBox::Cancel) == QMessageBox::Yes)
		this->close();
}

void TQANewWindow::on_actionabout_triggered()
{
	QMessageBox::about(this, tr(u8"关于"), tr(ABORT_IMFORMATION));
}

void TQANewWindow::mousePressEvent(QMouseEvent* qme)
{
	if (qme->button() == Qt::LeftButton)
	{
		if (qme->button() == Qt::LeftButton
			&& qme->pos().x() < this->nui.labelcr->geometry().right()
			&& (qme->pos().x() > this->nui.labelcr->geometry().left())
			&& (qme->pos().y() > this->nui.labelcr->geometry().top())
			&& (qme->pos().y() < this->nui.labelcr->geometry().bottom()))
		{
			mx = qme->pos().x();
			my = qme->pos().y();
			pressed = 1;
		}
		if (qme->button() == Qt::LeftButton
			&& os == 2
			&& qme->pos().x() < this->nui.labeltx->geometry().right()
			&& (qme->pos().x() > this->nui.labeltx->geometry().left())
			&& (qme->pos().y() > this->nui.labeltx->geometry().top())
			&& (qme->pos().y() < this->nui.labeltx->geometry().bottom()))
		{
			QMessageBox::information(this, u8"bug", u8"<html><head/><body><p><img src=\":/TestQtGuiApplication/Resources/ncxl.png\"/></p></body></html>");
		}
	}
}

void TQANewWindow::mouseMoveEvent(QMouseEvent* qme)
{
	if (pressed && qme->buttons() & Qt::LeftButton
		&& qme->pos().x() < this->nui.labelcr->geometry().right()
		&& (qme->pos().x() > this->nui.labelcr->geometry().left())
		&& (qme->pos().y() > this->nui.labelcr->geometry().top())
		&& (qme->pos().y() < this->nui.labelcr->geometry().bottom())
		)
	{
		ox = this->nui.labelcr->geometry().x();
		oy = this->nui.labelcr->geometry().y();
		ow = this->nui.labelcr->geometry().width();
		oh = this->nui.labelcr->geometry().height();
		this->nui.labelcr->setGeometry(ox + qme->pos().x() - mx, oy + qme->pos().y() - my, ow, oh);
		mx = qme->pos().x();
		my = qme->pos().y();
	}

}

void TQANewWindow::mouseReleaseEvent(QMouseEvent* qme)
{
	if (qme->button() == Qt::LeftButton
		&& qme->pos().x() < this->nui.labelcr->geometry().right()
		&& (qme->pos().x() > this->nui.labelcr->geometry().left())
		&& (qme->pos().y() > this->nui.labelcr->geometry().top())
		&& (qme->pos().y() < this->nui.labelcr->geometry().bottom()))
	{
		pressed = 0;
	}
}

void TQANewWindow::wheelEvent(QWheelEvent* qwe)
{
	if (qwe->delta() > 0)
		sc += 0.1f;
	else
		sc -= 0.1f;
	if (sc <= 0.1f)
		sc = 0.1f;
	if (sc >= 5.0f)
		sc = 5.0f;

	this->nui.labelcr->setGeometry(QRect(
		this->nui.labelcr->geometry().x(),
		this->nui.labelcr->geometry().y(),
		ow * sc,
		oh * sc
	));
}

void TQANewWindow::on_pushButtont1_clicked()
{
	this->nui.labeltx->setText(u8"<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; text-decoration: underline; color:#0000ff;\">使用拖动和滚轮改变小车的位置和大小</span></p></body></html>");
	os = 1;
}

void TQANewWindow::on_pushButtont2_clicked()
{
	this->nui.labeltx->setText(u8"<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic; text-decoration: underline; color:#00ff00;\">ps:玩滚轮会......（已修复）</span></p></body></html>");
	os = 2;
}
