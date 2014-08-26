#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include "QuashData.h"


class MaxHeap
{
    public:
        MaxHeap();
        virtual ~MaxHeap();
        void insert(QuashData* newItem);
        int deleteMax();
        void print();
        bool remove(int spot);


    private:

    int numElements;
    const static int maxElements = 42;

    void swap(int childIndex, int parentIndex);
    int parent(int child);
    void findSpot(int position);

    //our "heap" is a dynamically allocated array of pointers to
    //dynamically allocated QuashData objects
    QuashData** heap;
};

#endif // MAXHEAP_H
