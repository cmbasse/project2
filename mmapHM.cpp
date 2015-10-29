#include <iostream>
#include <string>
using namespace std;
//mmapHM
template<typename Type>
class DArray2{
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
        DArray2(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArray2(){ 
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

struct Pairs2{
    string key;
    int value;
    Pairs2(string inkey, int invalue){
        setPairs(inkey, invalue);
    };
    Pairs2(){};
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

unsigned int FNV1b(const void *bytes, int len){
    unsigned int h = FNV_32_offset;
    for(int i = 0; i < len; ++i){
        unsigned char data = * ((unsigned char *) bytes + i);
        h ^= data;
        h *= FNV_32_prime;
    }
    return h;
}

int myhash2(const void *bytes, int len, int array_length){
    unsigned int hash = FNV1b(bytes, len);
    return hash % array_length;
}


class mmapHM{
    private:
    DArray2<Pairs2>* arrayOfPairs;
    int size_of_table;
    int num_entries;
    string deleted;
    public: 
    DArray2<Pairs2>* getArrayOfPairs(){
        return arrayOfPairs;
    }
    mmapHM(){
        deleted = "@!(09)DELETE8*342$";
        num_entries = 0;
        size_of_table = 1000;
        arrayOfPairs = new DArray2<Pairs2>[size_of_table];
        
    }
    void set(string key, int value){
        int hash_value = myhash2(&*key.begin(), key.length(), size_of_table);
            Pairs2 p;
            p.setPairs(key, value);
        arrayOfPairs[hash_value].add(p);
    }
    
    int count(string key){
        int answer = 0;
        int hash_value = myhash2(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                answer++;
            }
        }
        return answer;
    }
    
    // bool is_in(string key){
    //     int location = static_cast<int>(key.at(0));
    //     for (int i = 0; i < arrayOfPairs[location].getSize(); i++){
    //         if (arrayOfPairs[location].getArray()[i].getKey() == key){
    //             return true;
    //         }
    //     }   
    //   return false; 
    // }
 
    int* getAll(string key){
        int answer[count(key)];
        int hash_value = myhash2(&*key.begin(), key.length(), size_of_table);
        for (int i = 0, j = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                    answer[j] = arrayOfPairs[hash_value].getArray()[i].getValue();
                    j++;
                }
        }
        int* copy = answer;
        return copy;
    }
    void rmoveAll(string key){
        int hash_value = myhash2(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                arrayOfPairs[hash_value].getArray()[i].setPairs(deleted, 0);
            }
        }
        
        
    }
    
    string removeOnePair(string key, int value){
        int hash_value = myhash2(&*key.begin(), key.length(), size_of_table);
        for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
            if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                if (arrayOfPairs[hash_value].getArray()[i].getValue() == value){
                    arrayOfPairs[hash_value].getArray()[i].setPairs(deleted, 0);
                    return "deleted one";
                }
            }
        }
        return "not present";
    }
    
    
};

