#ifndef PROJECT_2_SETLL_H
#define PROJECT_2_SETLL_H
#include <iostream>
#include "math.h"
#include "node.h"
#include <vector>
#include <string>



class setLL{

public:
    setLL();

    void insert(std::string key);
    void rmove(std::string key);
    void toString();

    bool is_in(std::string key);
    int size();
    bool is_empty();
    
    setLL unin(setLL &other_set);
    setLL intersection(setLL &other_set);

    ~setLL();
private:
    int* first;
    int* last;
    int length = 0;
};
#endif //PROJECT_2_SETLL_H