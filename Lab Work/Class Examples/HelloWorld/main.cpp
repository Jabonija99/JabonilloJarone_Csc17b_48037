
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QString>

//New Libraries



int main(int argc, char *argv[])
{   //Begins Qt Execution
    QApplication a(argc, argv);

    //Create String to write
    QString display="Hello world!";

    //Creates a new display label
    QLabel *label = new QLabel(display);

    //Show label
    label->show();

    //Exit program
    return a.exec();
}
