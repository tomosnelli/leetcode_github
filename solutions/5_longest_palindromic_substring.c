/*
    5. Longest Palindromic Substring
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* dynamic programming approach */
char* longestPalindrome(char* s)
{
    int n = strlen(s);
    bool dp[n][n];

    int start = 0;
    int max_length = 1;

    for(int i = 0; i < n; ++i){
        dp[i][i] = true;
    }

    for(int i = n-1; 0 <= i; --i){
        for(int j = i+1; j < n; ++j){
            if(s[i] == s[j]){
                if(j - i == 1){
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            } else {
                dp[i][j] = false;
            }

            if(dp[i][j] && max_length < j - i + 1){
                max_length = j - i + 1;
                start = i;
            }
        }
    }
    char* result = (char*) malloc((max_length + 1) * sizeof(char));
    strncpy(result, s + start, max_length);
    result[max_length] = '\0';

    return result;
}

int main() {
    char* input = "babad";
    char* result = longestPalindrome(input);
    printf("Longest palindromic substring: %s\n", result);
    free(result);
    return 0;
}