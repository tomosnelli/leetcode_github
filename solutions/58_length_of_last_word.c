/*
    58. Length of Last Word
*/
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
#define END '\0'

char* moveToWord(char* s){
    while(*s == SPACE && *s != END){
        ++s;
    }

    return s;
}

int countWord(char* s){
    if(*s == END) return 0;

    int count = 0;

    while(*s != END && *s != SPACE){
        ++count;
        ++s;
    }

    return count;
}

int lengthOfLastWord(char* s){
    int count = 0;

    while(*s != END){
        s = moveToWord(s);
        int temp = countWord(s);
        count = temp > 0 ? temp : count;
        s += temp;
    }

    return count;
}