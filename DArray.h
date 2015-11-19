#ifndef PROJECT_2_DArray_H
#define PROJECT_2_DArray_H
#include <iostream>
#include <string>
template<typename Type>
class DArray{
    private:
        unsigned long limit; 
        unsigned long size;
        Type* theData;
        void resize(unsigned long newSize);
        void addMoreData(Type inData);
        Type* getData(Type search);

    public:
        DArray();
        
        int getSize();
        void add(Type inData);
        Type* getArray();
        
        ~DArray();
};

#endif //PROJECT_2_DArray_H