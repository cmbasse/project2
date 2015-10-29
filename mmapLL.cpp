#include "mmapLL.h"

mmapLL::mmapLL(){}

void mmapLL::set(std::string key, int value){
    node *newNode = new node(key, value);

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
void mmapLL::rmoveOne(std::string key){
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
void mmapLL::rmoveAll(std::string key){
    bool end = false;
    node *me = (node *) first;
    node *lasts = (node *) last;
    
    int len = count(key);
    if(len == length){
        end = true;
        while(me->getNext() != 0){
            node *next = (node *) me->getNext();
            delete me;
            me = next;
        }
        delete me;
        length = 0;
        first = nullptr;
        last = 0;
    }

    if(me->getKey() == key && end == false){//trying to remove first node in list
        node *next = (node *) me->getNext();
        next->setLast(nullptr);
        first = (int *) next;
        delete me;
        me = (node *) first;
    }
    if(lasts->getKey() == key && end == false){//trying to remove last node in list
        node *prev = (node *) lasts->getLast();
        prev->setNext(0);
        last = (int *) prev;
        delete lasts;
    }

    while(!end){
        if (me->getKey() == key){
            if(me->getLast() == nullptr){//trying to remove first node
                node *next = (node *) me->getNext();
                next->setLast(nullptr);
                first = (int *) next;
                delete me;
            }else if(me->getNext() == 0){//trying to remove last node
                node *prev = (node *) me->getLast();
                prev->setNext(0);
                last = (int *) prev;
                delete me;
            }else{
                node *last = (node *) me->getLast();
                node *next = (node *) me->getNext();
    
                last->setNext((int *) next);
                next->setLast((int *) last);
    
                delete me;
            }
        }
        
        if (me->getNext() == 0){
            end = true;
        }else{
            me = (node *) me->getNext();
        }
        
    }
}
void mmapLL::toString(){
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

int mmapLL::count(std::string key){
    int len = 0;
    bool end = false;
    node *me = (node *) first;
    
    if(is_empty()){
        return len;
    }
    
    while(!end){
        if (me->getKey() == key){
            len += 1;
        }
        
        if (me->getNext() == 0){
            end = true;
        }else{
            me = (node *) me->getNext();
        }
    }
    return len;
}
int* mmapLL::getAll(std::string key){
    bool end = false;
    arr = new int[count(key)];
    node *me = (node *) first;
    int i = 0;
    
    if(is_empty()){
        end = true;
    }
    while(!end){
        if (me->getKey() == key){
            arr[i] = (int) me->getValue();
            i++;
        }
        
        if (me->getNext() == 0){
            end = true;
        }else{
            me = (node *) me->getNext();
        }
        
    }
    return arr;
}
int mmapLL::size(){
    return length;
}
bool mmapLL::is_empty(){
    return (length > 0)?false : true;
}

mmapLL::~mmapLL(){
    if(length > 0){
        node *me = (node *) first;
        while(me->getNext() != 0){
            node *next = (node *) me->getNext();
            delete me;
            me = next;
    
        }
        delete me;
        delete [] arr;
    }
}