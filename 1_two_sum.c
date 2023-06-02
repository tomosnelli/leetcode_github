/*
    1. Two Sum
*/
#include <stdio.h>
#include "uthash.h"

typedef struct{
    int val;
    UT_hash_handle hh;
} HashTable;

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* return_array = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; ++i){
        for(int j = i+1; j < numsSize; ++j){
            if(nums[i] + nums[j] == target){
                return_array[0] = i;
                return_array[1] = j;
            }
        }
    }
    return return_array;
}