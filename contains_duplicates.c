#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

// solution with out hashmap
/*
int compare_int(const void* a, const void* b){
    return (*(int*) a - *(int*) b);
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare_int);

    for(int i = 0; i < numsSize; ++i){
        if(i != numsSize -1 && nums[i] == nums[i+1]) return true;
    }

  return false;
}
*/

// uthash solution
// time improves but space complexity goes bad
typedef struct
{
    int val;
    UT_hash_handle hh;
} HashTable;

bool containsDuplicate(int* nums, int numsSize)
{
    HashTable *hash_table = NULL;

    for(int i = 0; i < numsSize; ++i){
        HashTable *entry;
        HASH_FIND_INT(hash_table, nums + i, entry);
        if(!entry){
            entry = malloc(sizeof(HashTable));
            entry->val = nums[i];
            HASH_ADD_INT(hash_table, val, entry);
        } else {
            return true;
        }
    }
    return false;
}

void test_case1(){
    int nums[] = {1,2,3,4,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    assert(containsDuplicate(nums, numsSize) == false);
}

void test_case2(){
    int nums[] = {1,2,3,4,5,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    assert(containsDuplicate(nums, numsSize) == true);
}

void test_case3(){
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    assert(containsDuplicate(nums, numsSize) == false);
}

void test_case4(){
    int nums[] = {1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    assert(containsDuplicate(nums, numsSize) == true);
}

void test_case5(){
    int nums[] = {1,1,1,3,3,4,3,2,4,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    assert(containsDuplicate(nums, numsSize) == true);
}

int main()
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    printf("All tests passed successfully.\n");
    return 0;
}
