/*
    90. Subsets Ⅱ
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int compare_int(const void* a, const void* b)
{
    return (*(int*) a - *(int*) b);
}

void helper(
    int* nums,
    int numsSize,
    int* returnSize,
    int* columnSizes,
    int** result,
    int* subset,
    int current_subset_size,
    int start
)
{
    result[*returnSize] = malloc(current_subset_size * sizeof(int));
    columnSizes[*returnSize] = current_subset_size;
    memcpy(result[(*returnSize)++], subset, (current_subset_size*sizeof(int)));

    for(int i = start; i < numsSize; ++i){
        if(i > start && nums[i] == nums[i-1]) continue;
        subset[current_subset_size] = nums[i];
        helper(nums, numsSize, returnSize, columnSizes, result, subset, current_subset_size+1, i+1);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int maxSubsets = 1 << numsSize;
    int** result = (int**)malloc(maxSubsets * sizeof(int*));
    int* subset = (int*)malloc(10 * sizeof(int));
    int* columnSizes = malloc(maxSubsets * sizeof(int));
    int start = 0;
    int current_subset_size = 0;
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare_int);

    helper(nums, numsSize, returnSize, columnSizes, result, subset, current_subset_size, start);

    free(subset);
    *returnColumnSizes = columnSizes;

    return result;
}

void test_case1() {
    int nums[] = {1,2,2};
    int returnSize;
    int* returnColumnSizes;
    int** result = subsetsWithDup(nums, 3, &returnSize, &returnColumnSizes);

    assert(returnSize == 6);
    free(returnColumnSizes);
    free(result);
}

void test_case2() {
    int nums[] = {1};
    int returnSize;
    int* returnColumnSizes;
    int** result = subsetsWithDup(nums, 1, &returnSize, &returnColumnSizes);

    assert(returnSize == 2);
    free(returnColumnSizes);
    free(result);
}

void test_case3() {
    int nums[] = {1, 2, 3};
    int returnSize;
    int* returnColumnSizes;
    int** result = subsetsWithDup(nums, 3, &returnSize, &returnColumnSizes);

    assert(returnSize == 8);
    free(returnColumnSizes);
    free(result);
}

void test_case4() {
    int nums[] = {4,4,4,1,4};
    int returnSize;
    int* returnColumnSizes;
    int** result = subsetsWithDup(nums, 5, &returnSize, &returnColumnSizes);

    assert(returnSize == 10);
    free(returnColumnSizes);
    free(result);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    return 0;
}
