#include <iostream>
#include <string>
using namespace std;
//setHM
template<typename Type>
class DArray3{
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
        DArray3(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArray3(){ 
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

unsigned int FNV1d(const void *bytes, int len){
    unsigned int h = FNV_32_offset;
    for(int i = 0; i < len; ++i){
        unsigned char data = * ((unsigned char *) bytes + i);
        h ^= data;
        h *= FNV_32_prime;
    }
    return h;
}

int myhash3(const void *bytes, int len, int array_length){
    unsigned int hash = FNV1d(bytes, len);
    return hash % array_length;
}


class setHM{
    
    private:
    DArray3<string>* arrayOfStrings;
    int size_of_table;
    int num_entries;
    string deleted;
    
    public: 
    DArray3<string>* getArrayOfStrings(){
        return arrayOfStrings;
    }
    setHM(){
        deleted = "@!(09)DELETE8*342$";
        num_entries = 0;
        size_of_table = 1000;
        arrayOfStrings = new DArray3<string>[size_of_table];
        for (int i = 0; i < 1000; i++){
            arrayOfStrings[i].getArray()[0] = "";
        }
        
    }
    void insert(string key){
        int hash_value = myhash3(&*key.begin(), key.length(), size_of_table);
        if (!(is_in(key))){
        arrayOfStrings[hash_value].add(key);
        }
    }
    bool is_in(string key){
        int hash_value = myhash3(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                return true;
            }
        }   
      return false; 
    }
    void rmove(string key){
        int hash_value = myhash3(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
            if (arrayOfStrings[hash_value].getArray()[i] == key){
                arrayOfStrings[hash_value].getArray()[i] = deleted;
            }
        }
        
    }
    bool is_empty(){
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                if ((arrayOfStrings[i].getArray()[j] != deleted)
                || (arrayOfStrings[i].getArray()[j] != "")){
                    return false;
                }
            }
        }
        return true;
    }
    
    setHM unin(setHM other_set){
        setHM myunion;
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                myunion.insert(arrayOfStrings[i].getArray()[j]);
            }
        }
        for (int k = 0; k < size_of_table; k++){
            for (int l = 0; l < other_set.arrayOfStrings[k].getSize(); l++){
                myunion.insert(other_set.arrayOfStrings[k].getArray()[l]);
            }
        }
        setHM& copy = myunion;
        return copy;
    }
    
    setHM intersection(setHM other_set){
        setHM myinter;
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfStrings[i].getSize(); j++){
                if (other_set.is_in(arrayOfStrings[i].getArray()[j])){
                myinter.insert(arrayOfStrings[i].getArray()[j]);
                }
            }
        }
        for (int k = 0; k < size_of_table; k++){
            for (int l = 0; l < other_set.arrayOfStrings[k].getSize(); l++){
                if (is_in(arrayOfStrings[k].getArray()[l]) &&
                (!(myinter.is_in(arrayOfStrings[k].getArray()[l])))){
                myinter.insert(arrayOfStrings[k].getArray()[l]);
                }
            }
        }
        
        setHM& copy = myinter;
        return copy;
    }
};

