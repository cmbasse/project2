#include "pairs.h"

Pairs::Pairs(string inkey, int invalue){
    setPairs(inkey, invalue);
};
Pairs::Pairs(){};
string Pairs::getKey(){
    return key;
}
int Pairs::getValue(){
    return value;
}
void Pairs::setPairs(string inkey, int invalue){
    key = inkey;
    value = invalue;
}