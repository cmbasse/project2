#include <iostream>
#include <string>
using namespace std;

template<typename Type>
class DArrayW{
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
        DArrayW(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArrayW(){ 
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


struct PairsW{
    string key;
    int value;
    PairsW(string inkey, int invalue){
        setPairs(inkey, invalue);
    };
    PairsW(){};
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

class MapArr{
    private:
    DArrayW<PairsW> arrayOfPairs;
    public: 
    MapArr(){
        
    }
    DArrayW<PairsW> getArrayOfPairs(){
        return arrayOfPairs;
    }
    void set(string key, int value){
        if (!(is_in(key))){
            PairsW p;
            p.setPairs(key, value);
        arrayOfPairs.add(p);
        }
    }
    bool is_in(string key){
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                return true;
            }
        }   
      return false; 
    }
    int get(string key){
        //int location = static_cast<int>(key.at(0));
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                    return arrayOfPairs.getArray()[i].getValue();
                }
        }
        return 'N';
    }
    void rmove(string key){
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
            if (arrayOfPairs.getArray()[i].getKey() == key){
                arrayOfPairs.getArray()[i].setPairs("", 0);
            }
        }
    }
    bool is_empty(){
        for (int i = 0; i < arrayOfPairs.getSize(); i++){
                if (arrayOfPairs.getArray()[i].getKey() != ""){
                    return false;
                }  
            }
        
        return false;
    }
    
    int& operator[](string key){
        int answer = get(key);
        int& copy = answer;
        return copy;
    }
};

/*int main(){
    MapArr m;
    m.set("ah", 1);
    m.set("aa", 2);
    m.set("cl", 2);
    m.set("dl", 2);
    m.set("el", 2);
    m.set("fl", 2);
    m.set("gl", 2);
    m.set("hl", 2);
    m.set("il", 2);
    //m.set("as", 2);
    m.rmove("ah");
    //m.rmove("aa");
    cout << m["aa"] << endl;
    cout << m.is_in("aa") << endl;
    cout << m.is_in("ah") << endl;
    cout << m.is_empty() << endl;
    cout << m.get("il") << endl;
}*/