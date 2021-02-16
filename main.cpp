#include "cannibal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cannibal w;
    w.show();

    return a.exec();
}
