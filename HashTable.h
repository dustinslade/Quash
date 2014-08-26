#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "QuashData.h"


class HashTable
{
    public:
        HashTable();
        virtual ~HashTable();
        bool insert(QuashData* newItem);
        int find(int v);
        int remove(int v);
        void print();

    private:
        int numElements;
        int maxElements;
        int mod(int x, int y);


        QuashData** table;

};

#endif // HASHTABLE_H
