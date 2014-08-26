#ifndef QUASHDATA_H
#define QUASHDATA_H

const char EMPTY = 0; //no object has ever been stored here
const char TOMBSTONE = -1; //an object was here and was deleted
const char OCCUPIED = 1; //an object is here

class QuashData
{
    public:

        QuashData();
        virtual ~QuashData();
        char getStorageFlag() { return storageFlag; }
        void setStorageFlag(char val) { storageFlag = val; }
        int getKey() { return key; }
        void setKey(int val) { key = val; }
        int getValue() { return value; }
        void setValue(int val) { value = val; }
        int getHeapPos() { return heapPos; }
        void setHeapPos(int val) { heapPos = val; }

    protected:
    private:
        char storageFlag;
        int key;
        int value;
        int heapPos;
};

#endif // QUASHDATA_H
