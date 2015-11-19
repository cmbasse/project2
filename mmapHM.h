#ifndef PROJECT_2_MMAPHM_H
#define PROJECT_2_MMAPHM_H
#include "DArray.h"
#include "helper.h"
#include "pairs.h"
#include <iostream>
#include <string>
using namespace std;

class mmapHM{
    private:
        DArray<Pairs>* arrayOfPairs;
        int size_of_table;
        int num_entries;
        string deleted;
    public: 
        DArray<Pairs>* getArrayOfPairs();
        mmapHM();
        void set(string key, int value);
        
        int count(string key);
        
        // bool is_in(string key);
     
        int* getAll(string key);
        void rmoveAll(string key);
        
        string removeOnePair(string key, int value);
};

#endif //PROJECT_2_MMAPHM_H