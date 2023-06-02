/*
    151. Reverse Words in a String
*/
#include "../utils/common.h"

#define END '\0'

/*
// slow
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
*/

char* reverseWords(char* s) {
    int length = strlen(s);

    // Trim leading spaces
    int i = 0;
    while (i < length && s[i] == ' ') {
        i++;
    }

    // Remove extra spaces between words
    int j = 0;
    int k = 0;
    char prev = ' ';
    while (i < length) {
        if (!(s[i] == ' ' && prev == ' ')) {
            s[j++] = s[i];
        }
        prev = s[i];
        i++;
    }

    // Trim trailing spaces
    while (j > 0 && s[j - 1] == ' ') {
        j--;
    }

    // Null-terminate the string
    s[j] = '\0';
    length = j;

    // Reverse the entire string
    for (i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }

    // Reverse individual words
    i = 0;
    while (i < length) {
        int wordStart = i;
        int wordLength = 0;
        while (i + wordLength < length && s[i + wordLength] != ' ') {
            wordLength++;
        }
        for (k = 0; k < wordLength / 2; k++) {
            char temp = s[wordStart + k];
            s[wordStart + k] = s[i + wordLength - k - 1];
            s[i + wordLength - k - 1] = temp;
        }
        i = i + wordLength + 1;
    }

    return s;
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