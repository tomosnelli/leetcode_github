/*
    46. Permutations
*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    /* n! */
    int product = 1;
    for(int i = n; n > 0; --n){
        product *= n;
    }
    return product;
}

void swap(int* nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void backtrack(int* nums, int size, int** result, int* returnSize, int* returnColumnSizes, int first)
{
    if(first == size){
        int* temp = malloc(size * sizeof(int));

        for(int i = 0; i < size; ++i) temp[i] = nums[i];

        result[*returnSize] = temp;
        returnColumnSizes[*returnSize] = size;
        (*returnSize)++;
    }

    for(int i = first; i < size; ++i){
        swap(nums, first, i);
        backtrack(nums, size, result, returnSize, returnColumnSizes, first+1);
        swap(nums, first, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int arraySize = factorial(numsSize);
    int** result = malloc(arraySize * sizeof(int*));
    *returnColumnSizes = malloc(arraySize * sizeof(int));
    *returnSize = 0;
    backtrack(nums, numsSize, result, returnSize, *returnColumnSizes, 0);
    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int returnSize;
    int* returnColumnSizes;
    int** res = permute(nums, sizeof(nums) / sizeof(int), &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}