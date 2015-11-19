#ifndef PROJECT_2_MSETHM_H
#define PROJECT_2_MSETHM_H
#include "DArray.h"
#include "helper.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class msetHM{
    private:
    DArray<string>* arrayOfStrings;
    int size_of_table;
    int num_entries;
    string deleted;
    public: 
    DArray<string>* getArrayOfStrings();
    msetHM();
    void insert(string key);
    bool is_in(string key);
    void rmoveAll(string key);
    void rmoveOne(string key);
    bool is_empty();
    unsigned long count(string key);
    
    unsigned long countBag();
    
    string draw_random();
};

#endif //PROJECT_2_MSETHM_H