
#include <QApplication>
#include <QLabel>
#include <QString>

#include "tableinhert.h"

using namespace std;

int main(int argc, char *argv[])
{
    int rows=5;
    int cols=6;

    TableInhert tab("Problem3.txt",rows,cols);
    QString data("");

    //Copies normal table contents to string
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    data += naugT[i*cols+j] + " ";
            }
            data += "\n";
    }

    data+="\n";

    //Copies augmented table contents to strings
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    data += augT[i*(cols+1)+j] + " ";
            }
            data+="\n";
    }


    QApplication a(argc, argv);

    QLabel *tLabel1 = new QLabel(data);

    tLabel1->show();

    return a.exec();
}
