#include <QApplication> //Library for applications
#include <QLabel> //Library for label object

int main(int argc, char *argv[])
{
    //Creates Qt application to manage application wide resources
    QApplication app(argc, argv);
    //Creates a QT Label with an attatched string
    QLabel *label = new QLabel("Hello Qt!");
    //Create a Qt label with a modified string using HTML
    QLabel *label2 = new QLabel("<h2><i>Hello </i>"
                                "<font clor=red>Qt!</font></h2>");
    //Makes the labels visible
    label->show();
    label2->show();

    return app.exec();
}
