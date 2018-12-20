#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    WorkTime = 45;
    RestTime = 5;
    ui->spinWork->setValue(WorkTime);
    ui->spinRest->setValue(RestTime);
    ui->BtnApply->setDisabled(true);
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
