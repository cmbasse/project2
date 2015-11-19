#ifndef PROJECT_2_PAIRS_H
#define PROJECT_2_PAIRS_H
#include "DArray.h"
#include "helper.h"
#include <iostream>
#include <string>
using namespace std;


class Pairs{
    public:
        string key;
        int value;
        Pairs(string inkey, int invalue);
        Pairs();
        string getKey();
        int getValue();
        void setPairs(string inkey, int invalue);
};

#endif //PROJECT_2_PAIRS_H