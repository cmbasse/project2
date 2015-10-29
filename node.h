//
// Created by Christian on 10/1/2015.
//

#ifndef PROJECT_2_NODE_H
#define PROJECT_2_NODE_H

#include <iostream>
#include "math.h"
#include <vector>
#include <string>

class node{

public:
    node(std::string key, int value);
    void setKey(std::string key);
    void setValue(int value);
    void setNext(int* next);
    void setLast(int* last);
    void toString();

    std::string getKey();
    int getValue();
    int* getNext();
    int* getLast();

private:
    std::string key;
    int value;
    int* next;
    int* last;

};

#endif //PROJECT_2_NODE_H