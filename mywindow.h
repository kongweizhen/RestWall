#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);

signals:

    void closeMyWin(void);

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);


};

#endif // MYWINDOW_H
