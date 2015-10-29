#ifndef PROJECT_2_MMAPLL_H
#define PROJECT_2_MMAPLL_H
#include <iostream>
#include "node.h"
#include <string>
#include <vector>



class mmapLL{

public:
    mmapLL();

    void set(std::string key, int value);
    void rmoveOne(std::string key);
    void rmoveAll(std::string key);
    void toString();

    int count(std::string key);
    int* getAll(std::string key);
    int size();
    bool is_empty();
    

    ~mmapLL();
private:
    int* first;
    int* last;
    int* arr;
    int length = 0;
    
};
#endif //PROJECT_2_MMAPLL_H