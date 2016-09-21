
#include <QApplication>
#include <QLabel>
#include <iostream>

#include "tableinhert.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Create table
    int rows=5;
    int cols=6;
    TableInhert tab("Problem3.txt",rows,cols);
    //Create empty string
    QString data("");

    //Copy table contents
    const int *naugT=tab.getTable();
    //Retrieve values from table
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                //Assign values to string
                data+= QString::number(naugT[i*cols+j]);
                data+=" ";
            }
            data+="\n";
    }
    data+="\n";

    //Copy augmented table
    const int *augT=tab.getAugTable();
    //Retrieve values from table
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                //Assign values to string
                data+=QString::number(augT[i*(cols+1)+j]);
                data+=" ";
            }
            data+="\n";
    }

    //Create application window
    QApplication a(argc, argv);
    //Create label with data string
    QLabel *label = new QLabel(data);
    //Show label
    label->show();


    return a.exec();
}
