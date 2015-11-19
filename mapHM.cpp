#include "mapHM.h"
#include "DArray.cpp"

DArray<Pairs>* mapHM::getArrayOfPairs(){
    return arrayOfPairs;
}
mapHM::mapHM(){
    deleted = "@!(09)DELETE8*342$";
    num_entries = 0;
    size_of_table = 1000;
    arrayOfPairs = new DArray<Pairs>[size_of_table];
    
}
void mapHM::set(string key, int value){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    if (!(is_in(key))){
        Pairs p;
        p.setPairs(key, value);
    arrayOfPairs[hash_value].add(p);
    }
}
bool mapHM::is_in(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
            return true;
        }
    }   
  return false; 
}
int mapHM::get(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                return arrayOfPairs[hash_value].getArray()[i].getValue();
            }
    }
    return -5;
}
void mapHM::rmove(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
            arrayOfPairs[hash_value].getArray()[i].setPairs(deleted, 0);
        }
    }
    
    
}
bool mapHM::is_empty(){
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
int& mapHM::operator[](string key){
    int answer = get(key);
    int& copy = answer;
    return copy;
}

