/*
    151. Reverse Words in a String
*/
#include "../utils/common.h"

#define END '\0'

char* reverseWords(char* s){

    int length = strlen(s);

    char* copy = malloc((length + 1) * sizeof(char));
    strcpy(copy, s);

    char* token = strtok(copy, " ");
    char* words[length];
    int word_count = 0;

    while(token != NULL){
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    char* reversed = malloc((length + 1) * sizeof(char));
    reversed[0] = END;

    for(int i = word_count - 1; i >= 0; --i){
        strcat(reversed, words[i]);
        if(i > 0){
            strcat(reversed, " ");
        }
    }

    free(copy);

    return reversed;
}


int main(){
    char s[] = "Let's take Leetcode contest";
    // size = 27
    // length of last word is 7
    // starting point should be 21
    char * reversed = reverseWords(s);
    printf("%s\n", reversed);
    return 0;
}