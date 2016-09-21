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
