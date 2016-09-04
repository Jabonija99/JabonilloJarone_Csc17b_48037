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

#include "Table.h"

Table::Table(char* words, int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    
    table = new int[rows*cols];
    rowSum = new int[rows];
    colSum = new int[cols];
    
    total = 0;
    
    for(int i = 0; i < this->rows*this->cols; i++){
        table[i] = 100+i;
    }
    
    calcTable();
}

void Table::calcTable(){
    //Calculate rows
    for(int i = 0; i < rows; i++){
        int rowTot=0;
        
        for(int j = 0; j < cols; j++){
            rowTot += table[rows*i+j];
        }
        
        rowSum[rows] = rowTot; 
    }
    
    //Calculate columns
    for(int i = 0; i < cols; i++){
        int colTot = 0;
        
        for(int j = 0; j < rows; j++){
            colTot += table[cols*i+j];
        }
        
        colSum[cols] = colTot;
    }
    
    //Calculate Total
    for(int i = 0; i < rows; i++){
        total += rowSum[i];
    }
    for(int i = 0; i < cols; i++){
        total += colSum[i];
    }
    

}

