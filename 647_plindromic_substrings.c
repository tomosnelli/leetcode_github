/*
    647. Palindromic Substrings
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int start, int end, char* s)
{
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int countSubstrings(char* s)
{
    int len = strlen(s);
    int count = 0;

    for(int i = 0; i < len; ++i){
        for(int j = i; j < len; ++j){
            if(isPalindrome(i, j, s)){
                ++count;
            }
        }
    }

    return count;
}

// Test Case 1
void test_case1() {
    char str[] = "abc";
    int expected_output = 3;
    int output = countSubstrings(str);

    printf("Input: %s\n", str);
    printf("Expected Output: %d\n", expected_output);
    printf("Output: %d\n\n", output);
}

// Test Case 2
void test_case2() {
    char str[] = "aaa";
    int expected_output = 6;
    int output = countSubstrings(str);

    printf("Input: %s\n", str);
    printf("Expected Output: %d\n", expected_output);
    printf("Output: %d\n\n", output);
}

// Test Case 3
void test_case3() {
    char str[] = "abba";
    int expected_output = 6;
    int output = countSubstrings(str);

    printf("Input: %s\n", str);
    printf("Expected Output: %d\n", expected_output);
    printf("Output: %d\n\n", output);
}

// Test Case 4
void test_case4() {
    char str[] = "racecar";
    int expected_output = 11;
    int output = countSubstrings(str);

    printf("Input: %s\n", str);
    printf("Expected Output: %d\n", expected_output);
    printf("Output: %d\n\n", output);
}

// Test Case 5
void test_case5() {
    char str[] = "abcdef";
    int expected_output = 6;
    int output = countSubstrings(str);

    printf("Input: %s\n", str);
    printf("Expected Output: %d\n", expected_output);
    printf("Output: %d\n\n", output);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();

    return 0;
}