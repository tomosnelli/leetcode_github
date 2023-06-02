/*
    1. Two Sum
*/
#include <stdio.h>
#include "uthash.h"

typedef struct{
    int key;
    int index;
    UT_hash_handle hh;
} HashTable;

/*
// O(n^2) solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* return_array = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; ++i){
        for(int j = i+1; j < numsSize; ++j){
            if(nums[i] + nums[j] == target){
                return_array[0] = i;
                return_array[1] = j;
                break;
            }
        }
    }
    return return_array;
}
*/

// hash table
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    HashTable* hash_table = NULL;
    HashTable* entry = NULL;

    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize; ++i){
        int complement = target - nums[i];
        HASH_FIND_INT(hash_table, &complement, entry);

        if(entry){
            result[0] = entry->index;
            result[1] = i;
            break;
        }

        entry = malloc(sizeof(HashTable));
        entry->key = nums[i];
        entry->index = i;
        HASH_ADD_INT(hash_table, key, entry);
    }

    HASH_CLEAR(hh, hash_table);
    return result;
}