#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("RestWall");
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    sw = new SettingWidget();
    sw->ReadSettings();

    ui->spinWork->setValue(sw->WorkTime);
    WorkTime = sw->WorkTime;
    ui->spinRest->setValue(sw->RestTime);
    RestTime = sw->RestTime;

    ui->StaBtn->setEnabled(true);
    ui->ApplyBtn->setEnabled(false);
    ui->StopBtn->setEnabled(false);

    wt = new QTimer();
    connect(wt,SIGNAL(timeout()),this,SLOT(showRestWall()));
    rt = new QTimer();
    connect(rt,SIGNAL(timeout()),this,SLOT(closeRestWall()));

    createTrayIcon();//托盘小图标

}

void Widget::showRestWall()
{
    mywin = new MyWindow(&(sw->wst));
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

void Widget::on_ApplyBtn_clicked()
{
    sw->WriteSettings("Time/WorkTime",QString::number(WorkTime));
    sw-> WorkTime = WorkTime;
    sw->WriteSettings("Time/RestTime",QString::number(RestTime));
    sw-> RestTime = RestTime;
    ui->ApplyBtn->setEnabled(false);
    ui->StaBtn->setEnabled(true);
}

void Widget::on_CancelBtn_clicked()
{
    this->hide();
    //--如果有修改，点击取消后，恢复原来的设置
    if(ui->ApplyBtn->isEnabled())
    {
        ui->spinRest->setValue(RestTime);
        ui->spinWork->setValue(WorkTime);
        ui->ApplyBtn->setEnabled(false);
        ui->StaBtn->setEnabled(true);
    }
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

    //---设置托盘小图标菜单
    trayMenu = new QMenu(this);
    //---设置选项
    QAction *settingAct = new QAction(tr("设置"));
    connect(settingAct,SIGNAL(triggered()),this,SLOT(on_settingAct()));
    trayMenu->addAction(settingAct);

    QAction *exitAct = new QAction(tr("退出"));
    connect(exitAct,SIGNAL(triggered()),this,SIGNAL(lastWindowClosed()));
    trayMenu->addAction(exitAct);


    trayIcon->setContextMenu(trayMenu);
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


void Widget::on_spinWork_valueChanged(int arg1)
{
    if(arg1 != WorkTime)
    {
        WorkTime = arg1;
        ui->ApplyBtn->setEnabled(true);
        ui->StaBtn->setEnabled(false);
    }

}

void Widget::on_spinRest_valueChanged(int arg1)
{
    if(arg1 != RestTime)
    {
        RestTime = arg1;
        ui->ApplyBtn->setEnabled(true);
        ui->StaBtn->setEnabled(false);
    }
}

void Widget::on_settingAct()
{
    if(this->isVisible())
        this->hide();

    sw->show();
}

