#include "setHM.h"
#include "DArray.cpp"

DArray<string>* setHM::getArrayOfStrings(){
    return arrayOfStrings;
}
setHM::setHM(){
    deleted = "@!(09)DELETE8*342$";
    num_entries = 0;
    size_of_table = 1000;
    arrayOfStrings = new DArray<string>[size_of_table];
    for (int i = 0; i < 1000; i++){
        arrayOfStrings[i].getArray()[0] = "";
    }
    
}
void setHM::insert(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    if (!(is_in(key))){
    arrayOfStrings[hash_value].add(key);
    }
}
bool setHM::is_in(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
        if (arrayOfStrings[hash_value].getArray()[i] == key){
            return true;
        }
    }   
  return false; 
}
void setHM::rmove(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfStrings[hash_value].getSize(); i++){
        if (arrayOfStrings[hash_value].getArray()[i] == key){
            arrayOfStrings[hash_value].getArray()[i] = deleted;
        }
    }
    
}
bool setHM::is_empty(){
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

setHM setHM::unin(setHM other_set){
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

setHM setHM::intersection(setHM other_set){
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


