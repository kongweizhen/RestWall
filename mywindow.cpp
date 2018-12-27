#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Hello");
    //this->setWindowModality(Qt::ApplicationModal); //阻塞整个应用程序
    this->setWindowOpacity(0.8); //整体透明

    this->showFullScreen();
}

void MyWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        QMessageBox *msgBox =new QMessageBox(this);
        msgBox->setText("休息时间还没到！");
        msgBox->setInformativeText("要关闭窗口吗？");
        msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msgBox->exec();
        switch (ret) {
        case QMessageBox::Ok:
            emit(closeMyWin());
            break;
        default:
            //
            break;
        }

    }
}
