#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Creates button object
    QPushButton *button = new QPushButton("Quit");
    //Calls the qobjects properties to connect the button object with a signal handler
    //When the button is clicked from the window, it calls the system quit()
    QObject::connect(button, SIGNAL(clicked()),
                     &app, SLOT(quit()));
    //Show button
    button->show();
    return app.exec();
}
