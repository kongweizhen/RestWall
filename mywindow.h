#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QHBoxLayout>
#include "settingwidget.h"

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(WallSettings *ws, QWidget *parent = nullptr);
    void setLabel(QString);

signals:

    void closeMyWin(void);

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    double Opacity;
    QLabel *la;


};

#endif // MYWINDOW_H
