/*
    128. Longest Consecutive Sequence
*/
#include "utils/common.h"

int compare_int(const void* a, const void* b)
{
    return (*(int*) a - *(int*) b);
}

int longestConsecutive(int* nums, int numsSize)
{
    if(!numsSize) return 0;

    qsort(nums, numsSize, sizeof(int), compare_int);

    int count = 1;
    int max = 1;

    for(int i = 1; i < numsSize; ++i){
        if(nums[i] - nums[i-1] == 1){
            ++count;
        } else if(nums[i] != nums[i-1]){
            count = 1;
        }

        max = count > max ? count : max;
    }
    return max;
}

void test_case1() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = longestConsecutive(nums, numsSize);
    printf("Test Case 1: %d\n", result);  // Output: 4
}

void test_case2() {
    int nums[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = longestConsecutive(nums, numsSize);
    printf("Test Case 2: %d\n", result);  // Output: 9
}

int main() {
    test_case1();
    test_case2();
    return 0;
}
