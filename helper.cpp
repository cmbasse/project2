#include "helper.h"


unsigned int FNV(const void *bytes, int len){
    unsigned int h = FNV_32_offset;
    for(int i = 0; i < len; ++i){
        unsigned char data = * ((unsigned char *) bytes + i);
        h ^= data;
        h *= FNV_32_prime;
    }
    return h;
}

int myhash(const void *bytes, int len, int array_length){
    unsigned int hash = FNV(bytes, len);
    return hash % array_length;
}