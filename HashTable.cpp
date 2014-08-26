#include "HashTable.h"


HashTable::HashTable(){
    maxElements = 43;
    numElements = 0;
    table = new QuashData *[maxElements];

    for (int i = 0; i < maxElements; i++) {
        table[i] = new QuashData;
        table[i]->setStorageFlag(EMPTY);
    }
}

HashTable::~HashTable(){

}

bool HashTable::insert(QuashData* newItem){

    //make sure the table still has room
    if (numElements==maxElements){
        return 0;
    }

    newItem->setKey( mod(newItem->getValue(), 43) );
    newItem->setStorageFlag(OCCUPIED);

    //if the position hashed to is already empty then fill it with the newItem
    if (table[newItem->getKey()]->getStorageFlag() != OCCUPIED) {
        table[newItem->getKey()] = newItem;
        numElements++;
        return 1;
    }


    /*if the postition is taken by an item with a different value,
    we move through the table to find an appropriate spot and/or
    make sure the current entry is not a duplicate.
    */
    else if (table[newItem->getKey()]->getStorageFlag() == OCCUPIED){

        int i=0; int z = (newItem->getKey());
        while(i < 43){

            //make sure we loop back to the beginning of our table
            //instead of going out of bounds
            if (z == 43)
                z=0;

            //check to see if item is a duplicate
            if (table[z]->getValue() == newItem->getValue()){
                return 0;
            }

            //check vacancy of current spot and insert value if not OCCUPIED
            if (table[z]->getStorageFlag() != OCCUPIED) {
                table[z] = newItem;
                numElements++;
                return 1;
            }

            //increment iterators
            z++; i++;
        }

    }

    return 0;

}

int HashTable::find(int v){
    for (int i = 0; i < maxElements; i++) {
        if (table[i]->getStorageFlag() == OCCUPIED && table[i]->getValue() == v)
            return i;
    }

    return -1;
}

int HashTable::remove(int v){
    int i = find(v);
    if (i != -1){
        table[i]->setStorageFlag(TOMBSTONE);
        return table[i]->getHeapPos();
    }

    else
        return -1;

}

void HashTable::print(){

    for (int i = 0; i < maxElements; i++) {
        if (table[i]->getStorageFlag() == OCCUPIED)
            std::cout << table[i]->getValue() << " ";
    }

    std::cout << std::endl;

}

int HashTable::mod(int x, int y){
    return (x%y + y)%y;
}
