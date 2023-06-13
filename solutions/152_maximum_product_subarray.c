/*
    152. Maximum Product Subarray
*/
#include "../utils/common.h"

#define MAX(x, y)((x > y) ? x : y)
#define MIN(x, y)((x > y) ? y : x)

int maxProduct(int* nums, int numsSize){
    int max = nums[0];
    int min = nums[0];
    int res = nums[0];

    for(int i = 1; i < numsSize; ++i){
        if(nums[i] < 0){
            int temp = max;
            max = min;
            min = temp;
        }

        max = MAX(nums[i], max * nums[i]);
        min = MIN(nums[i], min * nums[i]);

        res = MAX(res, max);
    }
    return res;
}

void test_case1(){
    int nums[] = {2, 3, -2, 4};
    int size = sizeof(nums) / sizeof(int);

    int actual = maxProduct(nums, size);
    int expected = 6;
    printf("expected: %d\nactual: %d\n", expected, actual);
}

void test_case2(){
    int nums[] = {-2, 0, -1};
    int size = sizeof(nums) / sizeof(int);

    int actual = maxProduct(nums, size);
    int expected = 0;
    printf("expected: %d\nactual: %d\n", expected, actual);
}

int main(){
    test_case1();
    test_case2();
    return 0;
}