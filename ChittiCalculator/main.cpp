#include "widget.h"
#include "calculator.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setMaximumSize(3000,250);
    w.show();
    return a.exec();
}

