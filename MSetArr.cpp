#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template<typename Type>
class DArrayCpCp{
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
        DArrayCpCp(){ 
            size = 0;
            limit = 10;
            theData = new Type[limit];
        };
        
        ~DArrayCpCp(){ 
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

class MSetArr{
    private:
    DArrayCpCp<string> MSArr;
    public: 
    DArrayCpCp<string> getMSArr(){
        return MSArr;
    }
    MSetArr(){
    }
    void insert(string key){
        MSArr.add(key);
        }

    bool is_in(string key){
        for (int i = 0; i < MSArr.getSize(); i++){
            if (MSArr.getArray()[i] == key){
                return true;
            }
        }   
      return false;
      }
    void rmoveAll(string key){
        if (is_in(key)){
        for (int i = 0; i < MSArr.getSize(); i++){
               if (MSArr.getArray()[i] == key){
          MSArr.getArray()[i] = "";
            }
        }
        }
    }
    void rmoveOne(string key){
        if (is_in(key)){
        for (int i = 0; i < MSArr.getSize(); i++){
            if (MSArr.getArray()[i] == key){
                MSArr.getArray()[i] = "";
                break;
            }
        }
        }
    }
    bool is_empty(){
        for (int i = 0; i < MSArr.getSize(); i++){
            if ((MSArr.getArray()[i] != "")){
                return false;
            }
        }
    return true;
    }
    
    unsigned long count(string key){
        unsigned long answer = 0;
        for (int i = 0; i < MSArr.getSize(); i++){
            if (MSArr.getArray()[i] == key){
                answer++;
        }
    }
    return answer;
}
};

// int main(){
//     MSetArr a;
//     a.insert("ab");
//     a.insert("cd");
//     //a.rmove("bc");
//     a.insert("dd");
//     a.insert("ee");
//     //a.rmove("ff");
//     a.insert("zz");
//     a.insert("y");
//     a.insert("y");
//     a.rmoveOne("y");
//     cout << a.count("y") << endl;
//     cout << a.is_in("ab") << endl;
//     cout << a.is_in("y") << endl;
//     //a.rmove("flklflksdh");
//     cout << a.is_empty() << endl;
    
// }