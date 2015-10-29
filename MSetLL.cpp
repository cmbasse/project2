#include "MSetLL.h"

MSetLL::MSetLL(){}

void MSetLL::insert(std::string key){
    node *newNode = new node(key, 1);

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
void MSetLL::rmoveOne(std::string key){
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
void MSetLL::rmoveAll(std::string key){
    bool end = false;
    node *me = (node *) first;
    node *lasts = (node *) last;
    
    unsigned long len = count(key);
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

void MSetLL::toString(){
    bool isEnd = false;
    node *me = (node *) first;
    int i = 0;
    if(first == nullptr && last == 0){
        isEnd = true;
    }
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

bool MSetLL::is_in(std::string key){
    bool found = false;
    node *me = (node *) first;
    if(is_empty()){
        return false;
    }
    while(!found){
        if (me->getKey() == key){
            return true;
        }else{
            if (me->getNext() == 0){
                return false;
            }else{
                me = (node *) me->getNext();
            }
        }
    }
}

unsigned long MSetLL::count(std::string key){
    unsigned long len = 0;
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
int MSetLL::size(){
    return length;
}
bool MSetLL::is_empty(){
    return (length > 0)?false : true;
}
std::string MSetLL::draw_random(){
    node *me = (node *) first;
    
    srand(time(0));
    int randNum = rand()%(length + 1);
    
    for(int i = 0; i < randNum; i++){
        me = (node *) me->getNext();
    }
    
    
    return me->getKey();
}
MSetLL::~MSetLL(){
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