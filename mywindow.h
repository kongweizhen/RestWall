#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include "settingwidget.h"

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(WallSettings *ws, QWidget *parent = nullptr);

signals:

    void closeMyWin(void);

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    double Opacity;


};

#endif // MYWINDOW_H
