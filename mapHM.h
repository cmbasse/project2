#ifndef PROJECT_2_MAPHM_H
#define PROJECT_2_MAPHM_H
#include "DArray.h"
#include "helper.h"
#include "pairs.h"
#include <iostream>
#include <string>
using namespace std;

class mapHM{
    private:
        DArray<Pairs>* arrayOfPairs;
        int size_of_table;
        int num_entries;
        string deleted;
    public: 
        DArray<Pairs>* getArrayOfPairs();
        mapHM();
        void set(string key, int value);
        bool is_in(string key);
        int get(string key);
        void rmove(string key);
        bool is_empty();
        int& operator[](string key);
};

#endif //PROJECT_2_MAPHM_H