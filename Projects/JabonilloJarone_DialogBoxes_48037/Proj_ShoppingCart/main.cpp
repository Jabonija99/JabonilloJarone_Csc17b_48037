
#include <QApplication>
#include "checkout.h"
#include "forminfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormInfo *window = new FormInfo;
    window->show();

    return a.exec();
}
