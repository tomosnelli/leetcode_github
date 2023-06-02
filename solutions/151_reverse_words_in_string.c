/*
    151. Reverse Words in a String
*/
#include <stdio.h>
#include <string.h>

#define SPACE ' '
#define END '\0'

int getWordLength(char *s){
    int length = 0;
    while(*s != SPACE && *s != END){
        ++length;
        ++s;
    }
    return length;
}

void reverseOneWord(char *s, int size){
    int i;
    int j;
    for(i = 0, j = size - 1; i < j; ++i, --j){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char* reverseWords(char* s){
    char* ptr = s;
    while(*s != END){
        int size = getWordLength(s);
        reverseOneWord(s, size);
        for(int i = 0; i < size; ++i){
            ++s;
        }
        ++s;
    }
    return ptr;
}

int main(){
    char s[] = "Let's take Leetcode contest";
    char * reversed = reverseWords(s);
    printf("%s\n", reversed);
    return 0;
}