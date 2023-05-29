/*
    198. House Robber
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(x, y)((x > y) ? x : y)

int rob(int* nums, int numsSize)
{
    if(numsSize == 1) return nums[0];
    if(numsSize == 2) return MAX(nums[0], nums[1]);

    int* dp1 = malloc(numsSize * sizeof(int));
    int* dp2 = malloc(numsSize * sizeof(int));

    dp1[0] = nums[0];
    dp1[1] = MAX(nums[0], nums[1]);

    for(int i = 2; i < numsSize-1; ++i){
        dp1[i] = MAX(nums[i] + dp1[i-2], dp1[i-1]);
    }

    dp2[1] = nums[1];
    dp2[2] = MAX(nums[1], nums[2]);

    for(int i = 3; i < numsSize; ++i){
        dp2[i] = MAX(nums[i] + dp2[i-2], dp2[i-1]);
    }

    int result = MAX(dp1[numsSize - 2], dp2[numsSize - 1]);

    free(dp1);
    free(dp2);

    return result;
}

// Test Case 1
void test_case1()
{
    int nums[] = {2, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = rob(nums, numsSize);

    printf("Test Case 1: Expected Result: 3, Actual Result: %d\n", result);
}

// Test Case 2
void test_case2()
{
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = rob(nums, numsSize);

    printf("Test Case 2: Expected Result: 4, Actual Result: %d\n", result);
}

// Test Case 3
void test_case3()
{
    int nums[] = {0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = rob(nums, numsSize);

    printf("Test Case 3: Expected Result: 0, Actual Result: %d\n", result);
}

int main()
{
    test_case1();
    test_case2();
    test_case3();

    return 0;
}