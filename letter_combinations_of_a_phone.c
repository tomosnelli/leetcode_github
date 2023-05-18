/*
    17. Letter Combinations of a Phone Number
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIFF 48

void helper(
    char** map,
    char* permutation,
    int permu_size,
    int index,
    int* returnSize,
    char** result,
    char* digits)
{
    if(permu_size == index){
        // add to array
        permutation[index] = '\0';
        result[*returnSize] = malloc((permu_size+1) * sizeof(char));
        memcpy(result[*returnSize], permutation, (permu_size+1) * sizeof(char));
        ++(*returnSize);
    } else {
        char* alternatives = map[digits[index] - DIFF];
        for(int i = 0; i < strlen(alternatives); ++i){
            permutation[index] = alternatives[i];
            helper(map, permutation, permu_size, index+1, returnSize, result, digits);
            permutation[index] = '\0';
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
    if(digits == NULL || strlen(digits) == 0){
        *returnSize = 0;
        char** result = malloc(sizeof(char*));
        //result[0] = malloc(sizeof(char));
        return result;
    }

    // prepare result array
    *returnSize = 0;
    int result_size = 1000;
    char** result = malloc(result_size* sizeof(char*));

    // prepare the temp premutation array
    int permu_size = strlen(digits);
    char* permutation = malloc((permu_size+1) * sizeof(char));

    // create map for 0-9
    char* map[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    helper(map, permutation, permu_size, 0, returnSize, result, digits);

    return result;
}

void test() {
    int returnSize;
    char** results;

    // Test 1: Normal case
    results = letterCombinations("23", &returnSize);
    printf("Test 1:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("%s ", results[i]);
    }
    printf("\n");

    // Test 2: Single digit
    results = letterCombinations("2", &returnSize);
    printf("Test 2:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("%s ", results[i]);
    }
    printf("\n");

    // Test 3: Empty string
    results = letterCombinations("", &returnSize);
    printf("Test 3:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("%s ", results[i]);
    }
    printf("\n");

    // Test 4: Digit with 4 letters
    results = letterCombinations("7", &returnSize);
    printf("Test 4:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("%s ", results[i]);
    }
    printf("\n");
}

int main() {
    test();
    return 0;
}