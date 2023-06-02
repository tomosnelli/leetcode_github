#include <stdio.h>

int sum_of_sequence(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; ++i) sum += i;

    return sum;
}


int missingNumber(int* nums, int numsSize)
{
    int sum = 0;
    for(int i = 0; i < numsSize; ++i) sum += nums[i];

    sequence_sum = sum_of_sequence(numsSize);
    return sequence_sum - sum;
}

int main()
{
    int nums[] = { 0, 1 };
    int missing = missingNumber(nums, 2);
}