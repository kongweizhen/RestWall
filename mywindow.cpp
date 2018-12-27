#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Hello");
    //this->setWindowModality(Qt::ApplicationModal); //阻塞整个应用程序
    this->setWindowOpacity(0.8); //整体透明
    this->showFullScreen();

    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
              QBrush(QPixmap(":/images/images/rest.jpg").scaled(// 缩放背景图.
                  this->size(),
                  Qt::IgnoreAspectRatio,
                  Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);


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
