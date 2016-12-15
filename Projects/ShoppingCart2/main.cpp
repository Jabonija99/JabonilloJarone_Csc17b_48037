#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/imgs/deps/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Loading shop...");
    a.processEvents();

    MainWindow w;
    w.show();
    splash.finish(&w);


    return a.exec();
}
