#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Problem 4 Part 2: Contiguous arrays using new/delete

template<typename Type>
class DArray{
    private:
  
        unsigned long limit;
        unsigned long size;
    
        Type* theData;
        
    
        void resize(unsigned long newSize){
            
            Type* newData = new Type[newSize];
            
            
            for(unsigned long i = 0; i < size; i++){
                newData[i] = theData[i];
            }
            
            delete[] theData;
            
            theData = newData;
            
            limit = size;
        }
        
        void addMoreData(Type inData){
            
            if (size >= limit){
                resize(2 * limit);
            };
            
            theData[size] = inData;
            size++;
        };

        Type* getData(Type search){
            for(unsigned long i = 0; i < size; i++){
                if (theData[i] == search){
                    return &theData[i];
                }
            }
            return 0;
        };


    public:
        DArray(){ 
            size = 0;
            limit = 1;
            theData = new Type[limit];
        };
        
        ~DArray(){ 
            delete[] theData;
        };

    
        void add(Type inData){
                addMoreData(inData);
            
        };
        
        Type* getArray(){
            return theData;
        }
};


int main() {
    DArray<char> myArray;
    char theChar = 'a';
    for(int i = 0; i < 26; i++){
        myArray.add(theChar);
        theChar++;
        cout << myArray.getArray()[i] << endl;
        
    }
}