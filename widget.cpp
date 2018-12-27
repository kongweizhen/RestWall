#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("RestWall");
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    WorkTime = 5;
    RestTime = 5;
    ui->spinWork->setValue(WorkTime);
    ui->spinRest->setValue(RestTime);
    ui->BtnApply->setDisabled(true);

    ui->StopBtn->setEnabled(false);

    wt = new QTimer();
    connect(wt,SIGNAL(timeout()),this,SLOT(showRestWall()));
    rt = new QTimer();
    connect(rt,SIGNAL(timeout()),this,SLOT(closeRestWall()));

    createTrayIcon();//托盘小图标


}

void Widget::showRestWall()
{
    mywin = new MyWindow();
    connect(mywin,SIGNAL(closeMyWin()),this,SLOT(closeRestWall()));
    StopTimer(1);
    rt->start(RestTime*1000);
}

void Widget::closeRestWall()
{
    if(mywin)
    {
        mywin->close();
        delete mywin;
        StopTimer(2);
    }
    wt->start(WorkTime*1000);
}

void Widget::StopTimer(int index)
{
    if(index == 1) //暂停工作时间
    {
        wt->stop();
    }
    else if(index == 2) //暂停休息时间
    {
        rt->stop();
    }
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_BtnApply_clicked()
{
    WorkTime = ui->spinWork->value();
    RestTime = ui->spinRest->value();
}

void Widget::on_BtnCancel_clicked()
{
    this->hide();
}

void Widget::on_StaBtn_clicked()
{
    wt->start(WorkTime*1000);
    ui->StopBtn->setEnabled(true);
    ui->StaBtn->setEnabled(false);
    this->hide();

}

void Widget::on_StopBtn_clicked()
{
    wt->stop();
    rt->stop();
    ui->StopBtn->setEnabled(false);
    ui->StaBtn->setEnabled(true);
}

void Widget::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/images/cup.ico"));
    trayIcon->setToolTip("RestWallApp");
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    trayIcon->show();

}

void Widget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->show();
        //trayIcon->showMessage("hello","world");
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}
