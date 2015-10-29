#include "setLL.h"

setLL::setLL(){}

void setLL::insert(std::string key){
    node *newNode = new node(key, 1);
    
    bool in = this->setLL::is_in(key);
    
    if(!in){
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
void setLL::rmove(std::string key){
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
void setLL::toString(){
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

bool setLL::is_in(std::string key){
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
int setLL::size(){
    return length;
}
bool setLL::is_empty(){
    return (length > 0)?false : true;
}

setLL setLL::unin(setLL &other_set){
   setLL unioned;
   bool end = false;
   bool end2 = false;
   node *me = (node *) first;
   node *me2 = (node *) other_set.first;
  while(!end){
      std::string key = me->getKey();
      unioned.insert(key);
       
      if(me->getNext() == 0){
          end = true;
      }else{
          me = (node *) me->getNext();
      }
  }
  while(!end2){
      std::string key2 = me2->getKey();
      unioned.insert(key2);
       
      if(me2->getNext() == 0){
          end2 = true;
      }else{
          me2 = (node *) me2->getNext();
      }
  }
   return unioned;
}
setLL setLL::intersection(setLL &other_set){
    setLL intersected;
    node *lhs = (node *) first;
    node *rhs = (node *) other_set.first;
    
    bool lhs_end = false;
    bool rhs_end = false;
    int len = length;
    
    while(!lhs_end){
        std::string search = lhs->getKey();
        while(!rhs_end){
            if(search == rhs->getKey()){
                std::string tmp = rhs->getKey();
                intersected.insert(tmp);
            }
            
            if(rhs->getNext() == 0){
                rhs_end = true;
            }else{
                rhs = (node *) rhs->getNext();
            }
        }
        
        if(lhs->getNext() == 0){
            lhs_end = true;
        }else{
            rhs_end = false;
            rhs = (node *) other_set.first;
            lhs = (node *) lhs->getNext();
        }
    }
    
    return intersected;
}

setLL::~setLL(){
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