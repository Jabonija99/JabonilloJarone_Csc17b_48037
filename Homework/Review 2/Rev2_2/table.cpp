#include "table.h"


using namespace std;

Table::Table(char* words, int rows, int cols) {
    //Assign rows and columns
    this->rows = rows;
    this->cols = cols;

    //Create tables
    table = new int[rows*cols];
    rowSum = new int[rows];
    colSum = new int[cols];

    //Initiate total
    total = 0;

    for(int i = 0; i < this->rows*this->cols; i++){
           table[i] = 100+i;
    }

    //Calculate table
    calcTable();
}

void Table::calcTable(){
    //Calculate rows
    for(int i = 0; i < rows; i++){
        int rowTot=0;

        for(int j = 0; j < cols; j++){
            rowTot += table[rows*i+i+j];
        }

        rowSum[i] = rowTot;
    }

    //Calculate columns
    for(int i = 0; i < cols; i++){
        int colTot = 0;

        for(int j = 0; j < rows; j++){
            colTot += table[cols*j+i];
        }

        colSum[i] = colTot;
    }

    //Calculate Total
    for(int i = 0; i < rows; i++){
        total += rowSum[i];
    }
    for(int i = 0; i < cols; i++){
        total += colSum[i];
    }


}
