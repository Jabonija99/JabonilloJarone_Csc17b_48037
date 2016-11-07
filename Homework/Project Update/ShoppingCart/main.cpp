#include "mainwindow.h"
#include "item.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
/*

  TO DO LIST:

  * Move buttons from item to shopping cart.
  ** Set item slot as public
  ** Transition screen on button press
  * Create checkout class
  * Create complete class
  * Create stacked widgets
  ** Find a way to read button clicks from central widget

*/
