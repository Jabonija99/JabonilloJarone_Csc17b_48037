
#include <QApplication>
#include <QLabel>
#include <iostream>

#include "tableinhert.h"

using namespace std;

int main(int argc, char *argv[])
{
    int rows=5;
    int cols=6;
    TableInhert tab("Problem3.txt",rows,cols);
    QString data("");


    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                data+=naugT[i*cols+j];
                data+=" ";
            }
            data+="\n";
    }
    data+="\n";

    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                data+=augT[i*(cols+1)+j];
                data+=" ";
            }
            data+="\n";
    }

    QApplication a(argc, argv);
    QLabel *label = new QLabel(data);
    label->show();


    return a.exec();
}
