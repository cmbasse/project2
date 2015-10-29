#include <iostream>
#include <string>
using namespace std;
//mapHM
template<typename Type>
class DArray1{
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
        DArray1(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArray1(){ 
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

struct Pairs1{
    string key;
    int value;
    Pairs1(string inkey, int invalue){
        setPairs(inkey, invalue);
    };
    Pairs1(){};
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

#define FNV_32_prime 16777619
#define FNV_32_offset 2166136261

unsigned int FNV1a(const void *bytes, int len){
    unsigned int h = FNV_32_offset;
    for(int i = 0; i < len; ++i){
        unsigned char data = * ((unsigned char *) bytes + i);
        h ^= data;
        h *= FNV_32_prime;
    }
    return h;
}

int myhash1(const void *bytes, int len, int array_length){
    unsigned int hash = FNV1a(bytes, len);
    return hash % array_length;
}



class mapHM{
    private:
    DArray1<Pairs1>* arrayOfPairs;
    int size_of_table;
    int num_entries;
    string deleted;
    public: 
    DArray1<Pairs1>* getArrayOfPairs(){
        return arrayOfPairs;
    }
    mapHM(){
        deleted = "@!(09)DELETE8*342$";
        num_entries = 0;
        size_of_table = 1000;
        arrayOfPairs = new DArray1<Pairs1>[size_of_table];
        
    }
    void set(string key, int value){
        int hash_value = myhash1(&*key.begin(), key.length(), size_of_table);
        if (!(is_in(key))){
            Pairs1 p;
            p.setPairs(key, value);
        arrayOfPairs[hash_value].add(p);
        }
    }
    bool is_in(string key){
        int hash_value = myhash1(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                return true;
            }
        }   
      return false; 
    }
    int get(string key){
        int hash_value = myhash1(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                    return arrayOfPairs[hash_value].getArray()[i].getValue();
                }
        }
        return -5;
    }
    void rmove(string key){
        int hash_value = myhash1(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                arrayOfPairs[hash_value].getArray()[i].setPairs(deleted, 0);
            }
        }
        
        
    }
    bool is_empty(){
        for (int i = 0; i < size_of_table; i++){
            for (int j = 0; j < arrayOfPairs[i].getSize(); j++){
                if ((arrayOfPairs[i].getArray()[j].getKey() != "")
                || (arrayOfPairs[i].getArray()[j].getKey() != deleted)){
                    return false;
                }
                
            }
        }
        return true;
    }
    int& operator[](string key){
        int answer = get(key);
        int& copy = answer;
        return copy;
    }
    
};

