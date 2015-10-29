#ifndef PROJECT_2_MAPLL_H
#define PROJECT_2_MAPLL_H
#include <iostream>
#include "math.h"
#include "node.h"
#include <vector>
#include <string>



class mapLL{

public:
    mapLL();

    void set(std::string key, int value);
    void rmove(std::string key);
    void toString();

    int get(std::string key);
    int size();
    bool is_empty();
    
    int& operator[](std::string key);

    ~mapLL();
private:
    int* first;
    int* last;
    int length = 0;
};
#endif //PROJECT_2_MAPLL_H