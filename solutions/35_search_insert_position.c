/*
    35. Search Insert Position
*/
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while(left <= right){
        //mid = ((right + left) + (2 - 1)) / 2;
        mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;

        if(nums[mid] < target)
            left = mid + 1;
        else 
            right = mid - 1;
    }

    return left;
}