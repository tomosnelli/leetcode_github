/*
    238. Product of Array Except Self
*/
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int product = 1;

    for(int i = 0; i < numsSize; ++i){
        result[i] = product;
        product *= nums[i];
    }

    product = 1;

    for(int i = numsSize -1; i >=0; --i){
        result[i] *= product;
        product *= nums[i];
    }

    return result;
}