#include "settingwidget.h"
#include "ui_settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWidget)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::WindowModal);
}

void SettingWidget::ReadSettings()
{
    QSettings settings("restwall.ini",QSettings::IniFormat);
    WorkTime = settings.value("Time/worktime").toInt();
    RestTime = settings.value("Time/resttime").toInt();
    wst.Opacity  = settings.value("Wall/opacity").toDouble();
}

void SettingWidget::WriteSettings(QString s, QString t)
{
    QSettings settings("restwall.ini",QSettings::IniFormat);
    settings.setValue(s,t);
}

SettingWidget::~SettingWidget()
{
    delete ui;
}
