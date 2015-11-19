#include "mmapHM.h"
#include "DArray.cpp"

DArray<Pairs>* mmapHM::getArrayOfPairs(){
    return arrayOfPairs;
}
mmapHM::mmapHM(){
    deleted = "@!(09)DELETE8*342$";
    num_entries = 0;
    size_of_table = 1000;
    arrayOfPairs = new DArray<Pairs>[size_of_table];
    
}
void mmapHM::set(string key, int value){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
        Pairs p;
        p.setPairs(key, value);
    arrayOfPairs[hash_value].add(p);
}

int mmapHM::count(string key){
    int answer = 0;
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
            answer++;
        }
    }
    return answer;
}

// bool mmapHM::is_in(string key){
//     int location = static_cast<int>(key.at(0));
//     for (int i = 0; i < arrayOfPairs[location].getSize(); i++){
//         if (arrayOfPairs[location].getArray()[i].getKey() == key){
//             return true;
//         }
//     }   
//   return false; 
// }

int* mmapHM::getAll(string key){
    int answer[count(key)];
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0, j = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
                answer[j] = arrayOfPairs[hash_value].getArray()[i].getValue();
                j++;
            }
    }
    int* copy = answer;
    return copy;
}
void mmapHM::rmoveAll(string key){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
    for (int i = 0; i < arrayOfPairs[hash_value].getSize(); i++){
        if (arrayOfPairs[hash_value].getArray()[i].getKey() == key){
            arrayOfPairs[hash_value].getArray()[i].setPairs(deleted, 0);
        }
    }
    
    
}

string mmapHM::removeOnePair(string key, int value){
    int hash_value = myhash(&*key.begin(), key.length(), size_of_table);
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

