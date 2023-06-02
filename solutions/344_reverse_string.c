/*
    344. Reverse String
*/
#include <stdio.h>

void reverseString(char* s, int sSize){
    int i, j = 0, sSize - 1;
    for(i = 0, j = sSize - 1; i < j; ++i, --j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(){
    return 0;
}