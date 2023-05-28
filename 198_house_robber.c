/*
    198. House Robber
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y)((x > y) ? x : y)

int rob(int* nums, int numsSize)
{
    int* dp = malloc(numsSize * sizeof(int));

    if(numsSize == 1) return nums[0];

    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);

    for(int i = 2; i < numsSize; ++i){
        dp[i] = MAX(nums[i] + dp[i-2], dp[i-1]);
    }

    int result = dp[numsSize - 1];

    free(dp);

    return result;
}