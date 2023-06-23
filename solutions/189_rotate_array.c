/*
    189. Rotate Array
*/
#include "../utils/common.h"

void rotate(int* nums, int numsSize, int k){
    if(numsSize == k) return;

    k %= numsSize;

    int* buff = malloc(k * sizeof(int));

    // store last k elements in buffer
    memcpy(buff, nums+(numsSize-k), k * sizeof(int));

    // shift element to the right
    for(int i = numsSize - 1; i >= k; --i){
        nums[i] = nums[i - k];
    }

    memcpy(nums, buff, k * sizeof(int));
}