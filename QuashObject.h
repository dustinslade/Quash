#ifndef QuashObject_H
#define QuashObject_H

#include <iostream>
#include "HashTable.h"
#include "MaxHeap.h"
#include "QuashData.h"


class QuashObject
{
    public:
        QuashObject();
        virtual ~QuashObject();
        void insert(int value);
        void print();
        void deleteMax();
        void remove(int val);
        void find(int val);

    private:

    HashTable hTable;
    MaxHeap mHeap;

};

#endif // QuashObject_H
