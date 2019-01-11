#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QSettings>
#include <QDebug>

namespace Ui {
class SettingWidget;
}

struct WallSettings
{
    double Opacity; //休息界面的透明度

};

class SettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWidget(QWidget *parent = 0);
    ~SettingWidget();

    void ReadSettings();
    void WriteSettings(QString, QString);

    int WorkTime;
    int RestTime;

    WallSettings wst;

private:
    Ui::SettingWidget *ui;
};

#endif // SETTINGWIDGET_H
