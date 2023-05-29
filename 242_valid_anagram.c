/*
    242. Valid Anagram
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOWER_SIZE 26

bool isAnagram(char* s, char* t)
{
    int size = strlen(s);
    if(size != strlen(t)) return false;

    int s_count[LOWER_SIZE] = {0};
    int t_count[LOWER_SIZE] = {0};

    for(int i = 0; i < size; ++i){
        s_count[s[i] - 'a']++;
        t_count[t[i] - 'a']++;
    }

    for(int i = 0; i < LOWER_SIZE; ++i){
        if(s_count[i] != t_count[i]) return false;
    }
    return true;
}

int main(){
    return 0;
}