/*
    neetcode backtracking
    78. Subsets
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int* nums, int numsSize, int index, int** result, int* returnSize, int* columnSizes, int* subset, int subsetSize)
{
    result[*returnSize] = (int*) malloc(subsetSize * sizeof(int));
    memcpy(result[*returnSize], subset, subsetSize * sizeof(int));
    columnSizes[*returnSize] = subsetSize;
    (*returnSize)++;

    for(int i = index; i < numsSize; ++i){
        subset[subsetSize] = nums[i];
        dfs(nums, numsSize, i + 1, result, returnSize, columnSizes, subset, subsetSize + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int maxSubsets = 1 << numsSize;
    int** result = (int**) malloc(maxSubsets * sizeof(int*));
    int* columnSizes = (int*) malloc(maxSubsets * sizeof(int));

    int* subset = malloc(numsSize * sizeof(int));
    *returnSize = 0;

    dfs(nums, numsSize, 0, result, returnSize, columnSizes, subset, 0);
    free(subset);
    *returnColumnSizes = columnSizes;
    return result;
}


int main()
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}