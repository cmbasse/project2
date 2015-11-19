#include "msetHM.h"
#include "DArray.cpp"

DArray<string>* msetHM::getArrayOfStrings(){
    return arrayOfStrings;
}
msetHM::msetHM(){
    deleted = "@!(09)DELETE8*342$";
    num_entries = 0;
    size_of_table = 1000;
    arrayOfStrings = new DArray<string>[size_of_table];
    for (int i = 0; i < 1000; i++){
        arrayOfStrings[i].getArray()[0] = "";
    }
    
}
void msetHM::insert(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    arrayOfStrings[hash_value].add(key);
}
bool msetHM::is_in(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
        if (arrayOfStrings[hash_value].getArray()[i] == key){
            return true;
        }
    }   
  return false; 
}
void msetHM::rmoveAll(string key){
    if (is_in(key)){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
        if (arrayOfStrings[hash_value].getArray()[i] == key){
            arrayOfStrings[hash_value].getArray()[i] = deleted;
        }
    }
    }
}
void msetHM::rmoveOne(string key){
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
bool msetHM::is_empty(){
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
unsigned long msetHM::count(string key){
    unsigned long answer = 0;
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
        if (arrayOfStrings[hash_value].getArray()[i] == key){
            answer++;
        }
    }
    return answer;
}

unsigned long msetHM::countBag(){
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

string msetHM::draw_random(){
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
