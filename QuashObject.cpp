#include "QuashObject.h"

QuashObject::QuashObject(){
}

QuashObject::~QuashObject(){

}

void QuashObject::insert(int val){
    QuashData *newItem;
    newItem = new QuashData;
    newItem->setValue(val);

    if(hTable.insert(newItem)){
        mHeap.insert(newItem);
        std::cout << "item successfully inserted" << std::endl;
    }

    else
        std::cout<<"item already present"<<std::endl;

}

void QuashObject::print(){
    hTable.print();
    mHeap.print();
}

void QuashObject::deleteMax(){

    int temp = mHeap.deleteMax();

    if ( temp != NULL)
        std::cout << "max item "<< temp <<" deleted" << std::endl;

    else
        std::cout << "max item not present since table is empty" <<std::endl;

}

void QuashObject::remove(int val){
    int spot = hTable.remove(val);
    //bool ptr = hTable.remove(val);

    if (spot != -1){
        std::cout << "item succesfully deleted" << std::endl;
        mHeap.remove(spot);
    }

    else
        std::cout << "item not present in the table" << std::endl;


}

void QuashObject::find(int val){
    if(hTable.find(val) != -1)
        std::cout << "item found" << std::endl;
    else
        std::cout << "item not found" << std::endl;


}
