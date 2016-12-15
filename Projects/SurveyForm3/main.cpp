#include <QApplication>
#include "mainwindow.h"
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/imgs/deps/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Loading survey...");
    a.processEvents();

    MainWindow *window = new MainWindow();
    window->show();
    splash.finish(window);

    return a.exec();
}
