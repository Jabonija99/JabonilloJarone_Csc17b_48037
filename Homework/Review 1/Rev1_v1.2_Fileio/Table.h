/*
 * Project created by Jarone Jabonillo.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: Kauru99
 *
 * Created on September 2, 2016, 9:30 PM
 */

#ifndef TABLE_H
#define TABLE_H


class Table {
    protected:
        int rows;
        int cols;
        int *rowSum;
        int *colSum;
        int *table;
        int total;
        void calcTable(void);
    public:
        Table(char*, int, int);
        ~Table(){delete [] table; delete [] rowSum; delete [] colSum;};
        const int *getTable(void){return table;};
        const int *getRowSum(void){return rowSum;};
        const int *getColSum(void){return colSum;};
        int getTotal(void){return total;};
};

#endif /* TABLE_H */

