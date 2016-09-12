/*
 * Project created by Jarone Jabonillo.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 2, 2016, 9:29 PM
 */

#include <cstdlib>
#include <iostream>
#include "TableInhert.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
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

    return 0;
}

