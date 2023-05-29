/*
    300. Longest Increasing Subsequence
*/
#include <stdio.h>
#include <assert.h>

void print_array(int* nums, int numsSize)
{
    printf("[");
    for(int i = 0; i < numsSize; ++i){
        if(i == numsSize - 1) printf("%d", nums[i]);
        else printf("%d, ", nums[i]);
    }
    printf("]\n");
}

/* first attempt. not really dynamic approach but brute force
int lengthOfLIS(int* nums, int numsSize)
{
    // brute force
    int dp[numsSize];
    // starting point i
    for(int i = 0; i < numsSize; ++i){
        dp[i] = 1;

        // reasoning for pivot
        // if i only use
        // if(nums[i] < nums[j]
        // i'll get all numbers greater than the starting point
        // which is not a subsequence
        int pivot = nums[i];
        // iterate over starting from i to end of numsSize
        for(int j = i; j < numsSize; ++j){
            if(pivot < nums[j]){
                dp[i] += 1;
                pivot = nums[j];
            }
        }
    }

    //print_array(dp, numsSize);

    return 1;
}
*/

/* second attempt */
int lengthOfLIS(int* nums, int numsSize)
{
    if(numsSize == 1) return 1;

    int dp[numsSize];
    int max = 0;

    for(int i = 0; i < numsSize; ++i){
        dp[i] = 1;

        for(int j = 0; j < i; ++j){
            if(nums[i] > nums[j]){
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
            }
            max = dp[i] > max ? dp[i] : max;
        }
    }

    return max;
}

void test_case1() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Test Case 1: Expected output: 4, Actual output: %d\n", result);
}

void test_case2() {
    int nums[] = {0, 1, 0, 3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Test Case 2: Expected output: 4, Actual output: %d\n", result);
}

void test_case3() {
    int nums[] = {7, 7, 7, 7, 7, 7, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Test Case 3: Expected output: 1, Actual output: %d\n", result);
}

void test_case4() {
    int nums[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Test Case 4: Expected output: 6, Actual output: %d\n", result);
}

void test_case5() {
    int nums[] = {-2, -1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Test Case 5: Expected output: 2, Actual output: %d\n", result);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();

    return 0;
}
