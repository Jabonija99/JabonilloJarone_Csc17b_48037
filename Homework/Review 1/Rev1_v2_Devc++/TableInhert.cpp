/*
 * Project created by Jarone Jabonillo.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TableInhert.cpp
 * Author: Kauru99
 * 
 * Created on September 2, 2016, 9:30 PM
 */

#include "TableInhert.h"

TableInhert::TableInhert(char* words, int rows, int cols): Table(words, rows, cols) {
    //Create augmented table [rows+1 * cols+1]
    
    augTable = new int[(this->rows+1)*(this->cols+1)];
    
    //Loops through rows
    int index = 0;
    
    for(int i = 0; i < this->rows; i++){
        //Loops through columns
        for(int j = 0 ; j < this->cols; j++){
            //Copy table column contents to aug table
            augTable[index++] = table[this->rows*i+(i*1)+j];
        }
        
        //Add row sum to end of column
        augTable[index++] = rowSum[i];
    }
    
    //Loops through the columns
    for(int i = 0; i < this->cols; i++){
        //Copy column sums to end of table
        augTable[index++] = colSum[i];
    }
    
    //Copy total to last space of table
    augTable[index++] = total;
    
}



