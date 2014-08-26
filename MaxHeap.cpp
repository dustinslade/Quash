#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    numElements = 0;
    heap = new QuashData *[maxElements];
}

MaxHeap::~MaxHeap(){
    //dtor
}

void MaxHeap::insert(QuashData* newItem){

    //put new item at the end of our heap and set its position
    int spot = numElements;
    numElements++;
    heap[spot] = newItem;
    newItem->setHeapPos(spot);

    //if the item has parents (if not at spot 0) and
    //it is greater than its parents we swap it up
    while( spot != 0 && heap[spot]->getValue() > heap[parent(spot)]->getValue() ){
        swap(spot, parent(spot) );
        spot = parent(spot);
    }

}

int MaxHeap::parent(int child){
    //we can calculate the parent of any child
    return ( (child-1)/2 );
}

void MaxHeap::findSpot(int position){

    int leftChild; int rightChild; int newPos;

    while(position < numElements-2){

        leftChild = 2*(position)+1;
        rightChild = 2*(position)+2;

        //check if a left child is present in the list
        if(leftChild < numElements){
            newPos=leftChild;

            //check if there is a right child and if it is greater than the left child we will be
            //moving it up instead
            if ( leftChild < numElements-1 && heap[leftChild]->getValue() < heap[rightChild]->getValue() ){
            newPos = rightChild;
            }
        }
        //if there is no left child then there is no right child and we
        //know our item cannot be swapped down.
        else
            break;

        //if the item has children but it is greater than them we
        //know our item does not need to be swapped down.
        if (heap[position]->getValue() >= heap[newPos]->getValue())
            break;

        //our item must be swapped with the greater of its children
        swap(newPos, position);
        //we start the process over at our item's new position
        position = newPos;
    }


}

int MaxHeap::deleteMax(){


    //if there is something at location 0 to remove we lazy
    //delete it from our hash table and return its value
    if( remove(0) ){
        heap[numElements]->setStorageFlag(TOMBSTONE);
        return heap[numElements]->getValue();
    }

    //if there is nothing at position 0 to remove we must pass up a null value
    //for a check that happens in the calling function
    else
        return NULL;

}

void MaxHeap::print(){

    //run through heap and print values in order
    for (int i = 0; i < numElements; i++) {
        std::cout << heap[i]->getValue() << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::swap(int childIndex, int parentIndex){
    QuashData* temp = heap[parentIndex];
    heap[parentIndex] = heap[childIndex];
    heap[childIndex] = temp;

    heap[childIndex]->setHeapPos(childIndex);
    heap[parentIndex]->setHeapPos(parentIndex);
}

bool MaxHeap::remove(int spot){

    if (numElements == 0)
        return 0;

    numElements--;
    swap(numElements, spot);

    if (numElements > 1){
        findSpot(spot);
    }

    return 1;

}
