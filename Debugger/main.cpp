#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 自适应分辨率 需要加在QApplication实例化之前，否则无效。
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
