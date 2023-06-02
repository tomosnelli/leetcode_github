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

void test_case1()
{
    char *text1 = "abcde";
    char *text2 = "ace";
    int expected = 3;
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
}

void test_case2()
{
    char *text1 = "abc";
    char *text2 = "def";
    int expected = 0;
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
}

void test_case3()
{
    char *text1 = "a";
    char *text2 = "a";
    int expected = 1;
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
}

void test_case4()
{
    char *text1 = "abcdefghijklmnopqrstuvwxyz";
    char *text2 = "bdfhjlnprtvxz";
    int expected = 12;
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
}

void test_case5()
{
    char *text1 = "hello";
    char *text2 = "world";
    int expected = 2;
    int result = longestCommonSubsequence(text1, text2);
    assert(result == expected);
}

int main()
{
    test_case1();   
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    printf("Passed All Test Cases\n");
    return 0;
}