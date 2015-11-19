#include "DArray.h"


template<class Type>
void DArray<Type>::resize(unsigned long newSize){
    
    Type* newData = new Type[newSize];
    
    
    for(unsigned long i = 0; i < size; i++){
        newData[i] = theData[i];
    }
    
    delete[] theData;
    
    theData = newData;
    
    limit = size;
}

template<class Type>
void DArray<Type>::addMoreData(Type inData){
    
    if (size >= limit){
        resize(2 * limit);
    };
    
    theData[size] = inData;
    size++;
};

template<class Type>
Type* DArray<Type>::getData(Type search){
    for(unsigned long i = 0; i < size; i++){
        if (theData[i] == search){
            return &theData[i];
        }
    }
    return 0;
}

template<class Type>
DArray<Type>::DArray(){ 
    size = 0;
    limit = 10;
    theData = new Type[limit];
}

template<class Type>
int DArray<Type>::getSize(){
    return size;
}

template<class Type>
void DArray<Type>::add(Type inData){
        addMoreData(inData);
    
}

template<class Type>
Type* DArray<Type>::getArray(){
    return theData;
}

template<class Type>
DArray<Type>::~DArray(){ 
    delete[] theData;
}
