/*
    1143. Longest Common Subsequence
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int longestCommonSubsequence(char* text1, char* text2)
{
    int rows = strlen(text1), cols = strlen(text2);
    int** dp = malloc((rows+1) * sizeof(int*));
    for(int i = 0; i <= rows; ++i){
        dp[i] = malloc((cols + 1) * sizeof(int));
        memset(dp[i], 0, (cols+1)*sizeof(int));
    }

    for(int i = 1; i <= rows; ++i){
        for(int j = 1; j <= cols; ++j){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;    
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int result = dp[rows][cols];

    for(int i = 0; i <= rows; ++i){
        free(dp[i]);
    }
    free(dp);

    return result;
}

void runTest(char* text1, char* text2, int expected)
{
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
    printf("Test case passed: %s, %s => Expected: %d, Result: %d\n", text1, text2, expected, result);
}

int main()
{
    runTest("abcde", "ace", 3);
    runTest("abc", "def", 0);
    runTest("a", "a", 1);
    runTest("abcdefghijklmnopqrstuvwxyz", "bdfhjlnprtvxz", 13);
    runTest("hello", "world", 1);
    printf("Passed All Test Cases\n");
    return 0;
}