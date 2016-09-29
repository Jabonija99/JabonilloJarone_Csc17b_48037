
#include <QApplication>
#include "checkout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Checkout *window = new Checkout;
    window->show();

    return a.exec();
}
