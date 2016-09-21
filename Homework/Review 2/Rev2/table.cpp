/*
 * Project created by Jarone Jabonillo.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Table.cpp
 * Author: Kauru99
 *
 * Created on September 2, 2016, 9:30 PM
 */

#include <fstream>

#include "Table.h"

using namespace std;

Table::Table(char* words, int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    table = new int[rows*cols];
    rowSum = new int[rows];
    colSum = new int[cols];

    total = 0;


    //Open file
    ifstream file (words);
    //If the file is open
    if(file.is_open()){
        int i = 0, data;
        //Read data from file
        while(file >> data){
            //Assign values to table
            table[i]=data;
            //Increment index
            i++;
        }
    }
    //Close file
    file.close();

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

