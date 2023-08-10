#include "sport.h"

#include <QApplication>
#include <qglobal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sport w;
    w.show();
    return a.exec();
}
