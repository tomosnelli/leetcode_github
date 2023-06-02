/* 191. Number of 1 Bits

    Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

    Note:

        Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
        In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

    

    Example 1:

        Input: n = 00000000000000000000000000001011
        Output: 3
        Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

    Example 2:

        Input: n = 00000000000000000000000010000000
        Output: 1
        Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

    Example 3:

        Input: n = 11111111111111111111111111111101
        Output: 31
        Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

    

    Constraints:

        The input must be a binary string of length 32.

    
    Follow up: If this function is called many times, how would you optimize it?

*/

#include <stdio.h>
#include <stdint.h>

/* brute force */
int hammingWeight(n)
uint32_t n;
{
    int sum = 0;
    for(int i = 0; i < 32; ++i){
        if(n&1){
            ++sum;
        }
        n >>= 1;
    }

    return sum;
}

/* recursive */
int hammingWeight_rec(n)
uint32_t n;
{
    if(n <= 0){
        return 0;
    }

    return (n&1) + hammingWeight_rec(n>>1);
}

/* optimized */
int hammingWeight_op(n)
uint32_t n;
{
    int sum = 0;
    while(n){
        if(n&0b1){
            ++sum;
        }
        n >>= 1;
    }
    return sum;
}

void test1()
{
    uint32_t n = 0b00000000000000000000000000001011;
    int actual = hammingWeight(n);
    int expected = 3;
    printf(actual == expected ? "PASS\n" : "FAIL\n");
    printf("actual: %d\n", actual);
}

void test2()
{
    uint32_t n = 0b00000000000000000000000000001011;
    int actual = hammingWeight_rec(n);
    int expected = 3;
    printf(actual == expected ? "PASS\n" : "FAIL\n");
    printf("actual: %d\n", actual);
}

int main()
{
    test1();
    test2();
    return 0;
}