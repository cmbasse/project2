#include <iostream>
#include <string>
using namespace std;

template<typename Type>
class DArrayB{
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
        DArrayB(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArrayB(){ 
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

class SetArr{
    
private:
DArrayB<string> StArray;
public: 
SetArr(){ 
        }
DArrayB<string> getStArray(){
    return StArray;
}

void insert(string key){
        if (!(is_in(key))){
        StArray.add(key);
        }
    
}

bool is_in(string key){
        for (int i = 0; i < StArray.getSize(); i++){
            if (StArray.getArray()[i] == key){
                return true;
            }
        }   
      return false;
}

void rmove(string key){
    for (int i = 0; i < StArray.getSize(); i++){
        if (StArray.getArray()[i] == key){
           StArray.getArray()[i] = "";
        }
    }
}


bool is_empty(){
    for (int i = 0; i < StArray.getSize(); i++){
            if ((StArray.getArray()[i] != "")){
                return false;
            }
        }
    return true;
}

    // SetArr unin(SetArr other_set){
    //     SetArr myunion;
    //     for (int i = 0; i < StArray.getSize(); i++){
    //             myunion.insert(StArray.getArray()[i]);
    //         }
    //     for (int k = 0; k < other_set.StArray.getSize(); k++){
    //             myunion.insert(other_set.StArray.getArray()[k]);
    //         }
        
    //     SetArr& copy = myunion;
    //     cout << "Union size: " << copy.getStArray().getSize() << endl;
    //     return copy;
    // }
    
    //     SetArr intersection(SetArr other_set){
    //     SetArr myinter;
    //     for (int j = 0; j < other_set.StArray.getSize(); j++){
    //             if (other_set.is_in(StArray.getArray()[j])){
    //             myinter.insert(StArray.getArray()[j]);
    //             }
    //         }
        
    //     for (int l = 0; l < other_set.StArray.getSize(); l++){
    //             if (is_in(StArray.getArray()[l]) &&
    //             (!(myinter.is_in(StArray.getArray()[l])))){
    //             myinter.insert(StArray.getArray()[l]);
    //             }
    //         }
        
        
    //     SetArr& copy = myinter;
    //     return copy;
    // }
    

};

// int main(){
//     SetArr a;
//     a.insert("ah");
//     SetArr b;
//     b.insert("ha");
//     //b.insert("ha");
//     //b.insert("la");
//     //cout << a.is_in("ab") << endl;
//     //string b = "aqa";
//     //int hash_value = myhash(&*b.begin(), b.length(), 1000);
//     //cout << "answer: " << a.getArrayOfStrings()[hash_value].getArray()[0] << endl;
//     SetArr c = a.intersection(b);
//     //cout << "ha in a? " << a.is_in("ha") << endl;
//     //cout << "ha? " << b.is_in("ha") << endl;
//     cout << "ha in c?" << c.is_in("l;kdfs") << endl;
//     // cout << c.is_in("ba") << endl;
//     // cout << c.is_in("ba") << endl;
//     // cout << c.is_in("ha") << endl;
//     // cout << "ksdjfkd? " << c.is_in("lkjdshfk") << endl;
//     // cout << c.is_empty() << endl;
    
// }