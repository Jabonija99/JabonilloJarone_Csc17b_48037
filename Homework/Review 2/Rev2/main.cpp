#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QString>

#include "tableinhert.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int rows=5;
    int cols=6;

    TableInhert tab("Problem3.txt",rows,cols);

    //Copies normal table contents to string
    QString nTable [rows*cols];
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    nTable[i*cols+j] = naugT[i*cols+j];
            }
    }

    //Copies augmented table contents to strings
    QString aTable [(rows+1)*(cols+1)];
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    aTable[i*(cols+1)+j] = augT[i*(cols+1)+j];
            }
    }

    QLabel *tLabel1 = new QLabel(nTable);
    QLabel *tLabel2 = new QLabel(aTable);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            tLabel1[i*cols+j]->show();
        }
    }
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            tLabel2[i*(cols+1)+j]->show();
        }
    }

    return a.exec();
}
