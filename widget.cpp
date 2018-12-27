#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    WorkTime = 25;
    RestTime = 5;
    ui->spinWork->setValue(WorkTime);
    ui->spinRest->setValue(RestTime);
    ui->BtnApply->setDisabled(true);

    ui->StopBtn->setEnabled(false);

    wt = new QTimer();
    connect(wt,SIGNAL(timeout()),this,SLOT(showRestWall()));
    rt = new QTimer();
    connect(rt,SIGNAL(timeout()),this,SLOT(closeRestWall()));


}

void Widget::showRestWall()
{
    mywin = new MyWindow();
    connect(mywin,SIGNAL(closeMyWin()),this,SLOT(closeRestWall()));
    StopTimer(1);
    rt->start(5000);
}

void Widget::closeRestWall()
{
    if(mywin)
    {
        mywin->close();
        delete mywin;
        StopTimer(2);
        wt->start(5000);
    }

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

}

void Widget::on_BtnCancel_clicked()
{

}

void Widget::on_StaBtn_clicked()
{
    wt->start(5000);
    ui->StopBtn->setEnabled(true);
    ui->StaBtn->setEnabled(false);
}

void Widget::on_StopBtn_clicked()
{
    wt->stop();
    rt->stop();
    ui->StopBtn->setEnabled(false);
    ui->StaBtn->setEnabled(true);
}
