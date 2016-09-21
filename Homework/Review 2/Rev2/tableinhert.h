/*
 * Project created by Jarone Jabonillo.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TableInhert.h
 * Author: Kauru99
 *
 * Created on September 2, 2016, 9:30 PM
 */

#ifndef TABLEINHERT_H
#define TABLEINHERT_H

#include "Table.h"

class TableInhert: public Table{
    protected:
        int *augTable;
    public:
        TableInhert(char*, int, int);
        ~TableInhert(){delete []augTable;}
        const int *getAugTable(void){return augTable;}

};

#endif /* TABLEINHERT_H */

