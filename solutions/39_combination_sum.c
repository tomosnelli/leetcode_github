/*
    39. Combination Sum
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_RESULT 150
#define MAX_COMBO 30

void add_to_array(int** temp, int* temp_size, int *occupied_count, int value)
{
    if(*temp_size == *occupied_count){
        *temp_size += 5;
        *temp = realloc(*temp, (*temp_size)*sizeof(int));
        if(*temp == NULL){
            printf("Error: Memory Reallocation Failed at line 15");
            exit(1);
        }
    }

    (*temp)[(*occupied_count)++] = value;
}

void helper(
    int** result,
    int* returnSize,
    int* candidates,
    int candidatesSize,
    int** returnColumnSizes,
    int* combination,
    int* combination_size,
    int* occupied_count,
    int current_running_sum,
    int target,
    int start
)
{
    if(current_running_sum == target){
        result[*returnSize] = (int*) malloc(*occupied_count * sizeof(int));
        memcpy(result[*returnSize], combination, (*occupied_count * sizeof(int)));
        (*returnColumnSizes)[(*returnSize)++] = *occupied_count;
    }

    if(current_running_sum < target){
        for(int i = start; i < candidatesSize; ++i){
            add_to_array(&combination, combination_size, occupied_count, candidates[i]);
            helper(
                result, returnSize, candidates, candidatesSize, returnColumnSizes,
                combination, combination_size, occupied_count,
                current_running_sum + candidates[i], target, i
            );
            --(*occupied_count); // backtrack
        }
    }
}

int** combinationSum(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
)
{
    int combination_size = MAX_COMBO;
    int occupied_count = 0;
    int* combination = (int*) malloc(MAX_COMBO * sizeof(int));

    *returnSize = 0;
    int** result = (int**) malloc(MAX_RESULT * sizeof(int*));
    *returnColumnSizes = (int*) malloc(MAX_RESULT * sizeof(int));

    helper(result, returnSize, candidates, candidatesSize, returnColumnSizes, combination, &combination_size, &occupied_count, 0, target, 0);

    free(combination);

    return result;
}

void test_case1() {
    int candidates[] = {2,3,6,7};
    int candidatesSize = 4;
    int target = 7;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);

    // Expected output: [[2,2,3],[7]]
    assert(returnSize == 2);
    assert(returnColumnSizes[0] == 3);
    assert(returnColumnSizes[1] == 1);
    assert(result[0][0] == 2);
    assert(result[0][1] == 2);
    assert(result[0][2] == 3);
    assert(result[1][0] == 7);

    // Free memory
    free(result);
}

void test_case2() {
    int candidates[] = {2,3,5};
    int candidatesSize = 3;
    int target = 8;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);

    // Expected output: [[2,2,2,2],[2,3,3],[3,5]]
    assert(returnSize == 3);
    assert(returnColumnSizes[0] == 4);
    assert(returnColumnSizes[1] == 3);
    assert(returnColumnSizes[2] == 2);
    assert(result[0][0] == 2);
    assert(result[0][1] == 2);
    assert(result[0][2] == 2);
    assert(result[0][3] == 2);
    assert(result[1][0] == 2);
    assert(result[1][1] == 3);
    assert(result[1][2] == 3);
    assert(result[2][0] == 3);
    assert(result[2][1] == 5);

    // Free memory
    free(result);
}

void test_case3() {
    int candidates[] = {2};
    int candidatesSize = 1;
    int target = 1;
    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);

    // Expected output: []
    assert(returnSize == 0);

    // Free memory
    free(result);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    return 0;
}