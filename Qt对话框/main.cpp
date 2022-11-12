#include <QtGui/QApplication>
#include "Widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Dialog Test");
    w.show();
    
    return a.exec();
}
