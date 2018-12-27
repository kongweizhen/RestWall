#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
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

private slots:
    void on_BtnApply_clicked();

    void on_BtnCancel_clicked();

    void showRestWall();
    void closeRestWall();

    void on_StaBtn_clicked();

    void on_StopBtn_clicked();

private:
    Ui::Widget *ui;
    int WorkTime;
    int RestTime;
    int StartTime;
    QTimer *wt; //工作时间倒计时
    QTimer *rt; //休息时间倒计时

    MyWindow *mywin;

    void StopTimer(int index);


};

#endif // WIDGET_H
