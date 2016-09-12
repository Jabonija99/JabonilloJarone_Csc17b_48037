#include <QCoreApplication>
#include <iostream>
#include "tableinhert.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int rows=5;
        int cols=6;
        TableInhert tab("Problem3.txt",rows,cols);

        const int *naugT=tab.getTable();
        for(int i=0;i<rows;i++)
        {
                for(int j=0;j<cols;j++)
                {
                        cout<<naugT[i*cols+j]<<" ";
                }
                cout<<endl;
        }
        cout<<endl;
        const int *augT=tab.getAugTable();
        for(int i=0;i<=rows;i++)
        {
                for(int j=0;j<=cols;j++)
                {
                        cout<<augT[i*(cols+1)+j]<<" ";
                }
                cout<<endl;
        }

    return a.exec();
}
