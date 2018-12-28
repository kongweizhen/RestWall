#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置当最后一个可视窗口关闭是，程序不退出；
    a.setQuitOnLastWindowClosed(false);

    Widget w;
    w.show();
    a.connect(&w,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));

    return a.exec();
}

