/*
    40. Combination Sum 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_RESULT 150
#define MAX_COMBO 30

int compare_int(const void* a, const void* b)
{
    return (*(int*) a - *(int*) b);
}

void add_to_array(int** temp, int* temp_size, int *occupied_count, int value)
{
    if(*temp_size == *occupied_count){
        *temp_size += 5;
        *temp = realloc(*temp, (*temp_size)*sizeof(int));
        if(*temp == NULL){
            printf("Error: Memory Reallocation Failed at line 21");
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
            if(i > start && candidates[i] == candidates[i-1]) continue;
            add_to_array(&combination, combination_size, occupied_count, candidates[i]);
            helper(
                result, returnSize, candidates, candidatesSize, returnColumnSizes,
                combination, combination_size, occupied_count,
                current_running_sum + candidates[i], target, i+1
            );
            --(*occupied_count);
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    int combination_size = MAX_COMBO;
    int occupied_count = 0;
    int* combination = (int*) malloc(MAX_COMBO * sizeof(int));

    *returnSize = 0;
    int** result = (int**) malloc(MAX_RESULT * sizeof(int*));
    *returnColumnSizes = (int*) malloc(MAX_RESULT * sizeof(int));

    // sort candidates
    qsort(candidates, candidatesSize, sizeof(int), compare_int);
    helper(result, returnSize, candidates, candidatesSize, returnColumnSizes, combination, &combination_size, &occupied_count, 0, target, 0);

    free(combination);

    return result;
}