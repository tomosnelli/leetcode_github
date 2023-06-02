/*
    704. Binary Search
*/
//#include "../utils/common.h"
#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;

        if(nums[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return nums[left] == target ? left : -1;
}

void test_case1() {
    int nums[] = {2, 4, 6, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    int result = search(nums, numsSize, target);
    printf("Target: %d, Result: %d\n", target, result);
}

void test_case2() {
    int nums[] = {2, 4, 6, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int result = search(nums, numsSize, target);
    printf("Target: %d, Result: %d\n", target, result);
}

void test_case3() {
    int nums[] = {1, 3, 5, 7, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 3;
    int result = search(nums, numsSize, target);
    printf("Target: %d, Result: %d\n", target, result);
}

void test_case4() {
    int nums[] = {1, 3, 5, 7, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int result = search(nums, numsSize, target);
    printf("Target: %d, Result: %d\n", target, result);
}

void test_case5() {
    int nums[] = {2, 4, 6, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 11;
    int result = search(nums, numsSize, target);
    printf("Target: %d, Result: %d\n", target, result);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();

    return 0;
}
