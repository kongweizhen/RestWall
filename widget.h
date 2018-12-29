#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QSettings>
#include "mywindow.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:
    void lastWindowClosed();

private slots:

    void showRestWall();
    void closeRestWall();

    void on_StaBtn_clicked();

    void on_StopBtn_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason);

    void on_spinWork_valueChanged(int arg1);

    void on_spinRest_valueChanged(int arg1);

    void on_ApplyBtn_clicked();

    void on_CancelBtn_clicked();

private:
    Ui::Widget *ui;
    int WorkTime;
    int RestTime;
    int StartTime;
    QTimer *wt; //工作时间倒计时
    QTimer *rt; //休息时间倒计时

    MyWindow *mywin;
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;

    void StopTimer(int index);
    void createTrayIcon();

    void ReadSettings();
    void WriteSetting();


};

#endif // WIDGET_H
