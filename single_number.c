/* 136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1

 

Constraints:

    1 <= nums.length <= 3 * 10^4
    -3 * 104 <= nums[i] <= 3 * 10^4
    Each element in the array appears twice except for one element which appears only once.



*/

int singleNumber(int* nums, int numsSize){
    int single = 0;
    for(int i = 0; i < numSize; ++i){
        single ^= nums[i];
    }

    return single;
}

int main(){
    int array = [1, 2, 2, 3, 3];
    int single = singleNumber(array, 5);
    printf("%d\n", single);
    return 0;
}