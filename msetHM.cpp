#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//msetHM
template<typename Type>
class DArrayR{
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
        DArrayR(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArrayR(){ 
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
};

#define FNV_32_prime 16777619
#define FNV_32_offset 2166136261

unsigned int FNV1c(const void *bytes, int len){
    unsigned int h = FNV_32_offset;
    for(int i = 0; i < len; ++i){
        unsigned char data = * ((unsigned char *) bytes + i);
        h ^= data;
        h *= FNV_32_prime;
    }
    return h;
}

int myhash(const void *bytes, int len, int array_length){
    unsigned int hash = FNV1c(bytes, len);
    return hash % array_length;
}


class msetHM{
    private:
    DArrayR<string>* arrayOfStrings;
    int size_of_table;
    int num_entries;
    string deleted;
    public: 
    DArrayR<string>* getArrayOfStrings(){
        return arrayOfStrings;
    }
    msetHM(){
        deleted = "@!(09)DELETE8*342$";
        num_entries = 0;
        size_of_table = 1000;
        arrayOfStrings = new DArrayR<string>[size_of_table];
        for (int i = 0; i < 1000; i++){
            arrayOfStrings[i].getArray()[0] = "";
        }
        
    }
    void insert(string key){
        int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        arrayOfStrings[hash_value].add(key);
    }
    bool is_in(string key){
        int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                return true;
            }
        }   
      return false; 
    }
    void rmoveAll(string key){
        if (is_in(key)){
        int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                arrayOfStrings[hash_value].getArray()[i] = deleted;
            }
        }
        }
    }
    void rmoveOne(string key){
        if (is_in(key)){
        int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                arrayOfStrings[hash_value].getArray()[i] = deleted;
                break;
            }
        }
        }
    }
    bool is_empty(){
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                if ((arrayOfStrings[i].getArray()[j] != "") ||
                (arrayOfStrings[i].getArray()[j] != deleted)){
                    return false;
                }
            }
        }
        return true;
    }
    unsigned long count(string key){
        unsigned long answer = 0;
        int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                answer++;
            }
        }
        return answer;
    }
    
    unsigned long countBag(){
        unsigned long answer = 0;
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                if (arrayOfStrings[i].getArray()[j] != ""){
                    answer++;
                }
            }
        }
        return answer;
    }
    
    string draw_random(){
        int theCount = countBag();
        srand(time(NULL));
        int myRand = rand() % theCount;
        cout << myRand << endl;
        for (int i = 0, counter = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                if (arrayOfStrings[i].getArray()[j] == ""){
                }
                else {
                    if (counter == myRand){
                        return arrayOfStrings[i].getArray()[j];
                    }
                    counter++;
                }
            }
        }
        return "empty bag";
    }
};

