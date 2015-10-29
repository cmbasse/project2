#include <iostream>
#include <string>
using namespace std;

template<typename Type>
class DArrayF{
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
        DArrayF(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArrayF(){ 
            delete[] theData;
        };
        int getSize(){
            return size;
        }
    
        void add(Type inData){
                addMoreData(inData);
            
        };
        
        Type* getArray(){
            return theData;
        }
        
        Type getArray2(){
            return *theData;
        }
};

struct PairsF{
    string key;
    int value;
    PairsF(string inkey, int invalue){
        setPairs(inkey, invalue);
    };
    PairsF(){};
    string getKey(){
        return key;
    }
    int getValue(){
        return value;
    }
    void setPairs(string inkey, int invalue){
        key = inkey;
        value = invalue;
    };
};

class MMapArr{
    private:
    DArrayF<PairsF> arrayOfPairs;
    public: 
    MMapArr(){
        
    }
    DArrayF<PairsF> getArrayOfPairs(){
        return arrayOfPairs;
    }
    
    int getArraySize(){
        return arrayOfPairs.getSize();
    }
    
    void set(string key, int value){
            PairsF p;
            p.setPairs(key, value);
        arrayOfPairs.add(p);
    }
    
    int* getAll(string key){
        int answer[count(key)];
        for (int i = 0, j = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                    answer[j] = arrayOfPairs.getArray()[i].getValue();
                    j++;
                }
        }
        int* copy = answer;
        return copy;
    }
    
    void rmoveall(string key){
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                arrayOfPairs.getArray()[i].setPairs("", 0);
            }
        }
    }
    int count(string key){
        int count=0;
        for (int i=0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                count++;
            }
        }
        return count;
    }
    
    void rmoveOne(string key){
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                arrayOfPairs.getArray()[i].setPairs("", 0);
                break;
            }
        }
    
    }
 
};