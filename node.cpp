//
// Created by yes Christian on 10/1/2015.
//

#include "node.h"

node::node(std::string key, int value){
    this->key = key;
    this->value = value;
    this->next = 0;
    this->last = nullptr;
}
void node::setKey(std::string key){
    this->key = key;
}
void node::setValue(int value){
    this->value = value;
}
void node::setNext(int* next){
    this->next = next;
}
void node::setLast(int* last){
    this->last = last;
}

void node::toString(){
    std::cout << "KEY: " << key << " VALUE: " << value << std::endl;
}

std::string node::getKey() {
    return this->key;
}
int node::getValue(){
    return this->value;
}
int* node::getNext(){
    return this->next;
}
int* node::getLast(){
    return this->last;
}


