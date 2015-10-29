#ifndef PROJECT_2_MSETLL_H
#define PROJECT_2_MSETLL_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include <string>



class MSetLL{

public:
    MSetLL();

    void insert(std::string key);
    void rmoveOne(std::string key);
    void rmoveAll(std::string key);
    void toString();

    bool is_in(std::string key);
    unsigned long count(std::string key);
    int size();
    bool is_empty();
    std::string draw_random();

    ~MSetLL();
private:
    int* first;
    int* last;
    int length = 0;
};
#endif //PROJECT_2_MSETLL_H