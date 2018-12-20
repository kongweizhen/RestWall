#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private:
    Ui::Widget *ui;
    int WorkTime;
    int RestTime;
    int StartTime;


};

#endif // WIDGET_H
