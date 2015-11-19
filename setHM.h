#ifndef PROJECT_2_SETHM_H
#define PROJECT_2_SETHM_H
#include "DArray.h"
#include "helper.h"
#include <iostream>
#include <string>
using namespace std;

class setHM{
    
    private:
    DArray<string>* arrayOfStrings;
    int size_of_table;
    int num_entries;
    string deleted;
    
    public: 
    setHM();
    DArray<string>* getArrayOfStrings();
    void insert(string key);
    bool is_in(string key);
    void rmove(string key);
    bool is_empty();
    
    setHM unin(setHM other_set);
    
    setHM intersection(setHM other_set);
};

#endif //PROJECT_2_SETHM_H