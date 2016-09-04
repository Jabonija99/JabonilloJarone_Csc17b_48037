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
    /**
    this->rows = rows;
    this->cols = cols;
    
    table = new int[this->rows*this->cols];
    rowSum = new int[this->rows];
    colSum = new int[this->cols];
    
    total = 0;
    
    for(int i = 0; i < this->rows*this->cols; i++){
        table[i] = 100+i;
    }
    
    calcTable();
     * */
    
    augTable = new int[(this->rows+1)*(this->cols+1)];
    
    for(int i = 0; i < this->rows; i++){
        for(int j = 0 ; j < this->cols; j++){
            augTable[this->rows*i+j] = table[this->rows*i+j];
        }
        
        augTable[this->rows*i+this->cols] = rowSum[i];
    }
    
    for(int i = 0; i < this->cols; i++){
        augTable[this->rows*(this->rows+1)+i] = colSum[i];
    }
    
    augTable[(this->rows+1)*(this->cols+1)] = total;
    
}


