/*
    387. First Unique Character in a String
*/
#include "../utils/common.h"

#define DIFF 'a'

int firstUniqChar(char * s){
    int array[26] = {0};
    int length = strlen(s);

    for(int i = 0; i < length; ++i){
        array[s[i] - DIFF] += 1;
    }

    for(int i = 0; i < length; ++i){
        if(array[s[i] - DIFF] == 1) return i;
    }

    return -1;
}