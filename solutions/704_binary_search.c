/*
    704. Binary Search
*/
#include "../utils/common.h"

int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            left = mid + 1;
        }
    }
}