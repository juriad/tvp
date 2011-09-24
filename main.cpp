#include "tvp.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TVP w;
    w.show();
    return a.exec();
}
