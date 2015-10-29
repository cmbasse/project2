#include "mapLL.h"

mapLL::mapLL(){}

void mapLL::set(std::string key, int value){
    node *newNode = new node(key, value);
    
    int in = this->mapLL::get(key);
    
    if(in < 0 ){
        if(is_empty()){
            first = (int *) newNode;
            last = (int *) newNode;
            length = 1;
        }else{
            node *lastNode = (node *) last;
        
            newNode->setLast(last);
            lastNode->setNext((int *) newNode);
        
            last = (int *) newNode;
            length += 1;
        }
    }
}
void mapLL::rmove(std::string key){
    bool found = false;
    node *me = (node *) first;
    node *lasts = (node *) last;

    if(me->getKey() == key){//trying to remove first node in list
        found = true;
        node *next = (node *) me->getNext();
        next->setLast(nullptr);
        first = (int *) next;
        delete me;
    }
    if(lasts->getKey() == key && found == false){//trying to remove last node in list
        found = true;
        node *prev = (node *) lasts->getLast();
        prev->setNext(0);
        last = (int *) prev;
        delete lasts;
    }

    while(!found){
        if (me->getKey() == key){
            found = true;
            node *last = (node *) me->getLast();
            node *next = (node *) me->getNext();

            last->setNext((int *) next);
            next->setLast((int *) last);

            delete me;
        }else{
            if (me->getNext() == 0){
                found = true;
            }else{
                me = (node *) me->getNext();
            }
        }
    }
}
void mapLL::toString(){
    bool isEnd = false;
    node *me = (node *) first;
    int i = 0;
    while(!isEnd){

        std::cout << "NODE: " << i << " ";
        me->toString();

        if (me->getNext() == 0){
            isEnd = true;
        }else{
            me = (node *) me->getNext();
        }
        i++;
    }
}

int mapLL::get(std::string key){
    bool found = false;
    node *me = (node *) first;
    if(is_empty()){
        return -2;
    }
    while(!found){
        if (me->getKey() == key){
            return me->getValue();
        }else{
            if (me->getNext() == 0){
                return -1;
            }else{
                me = (node *) me->getNext();
            }
        }
    }
}
int mapLL::size(){
    return length;
}
bool mapLL::is_empty(){
    return (length > 0)?false : true;
}


int& mapLL::operator[](std::string key){ 
    int val = this->get(key);
    int& copy = val;
    return copy;
}

mapLL::~mapLL(){
    if(length > 0){
        node *me = (node *) first;
        while(me->getNext() != 0){
            node *next = (node *) me->getNext();
            delete me;
            me = next;
    
        }
        delete me;
    }
}