/* 190. Reverse Bits

    Reverse bits of a given 32 bits unsigned integer.

    Note:

        Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
        In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

 

    Example 1:

        Input: n = 00000010100101000001111010011100
        Output:    964176192 (00111001011110000010100101000000)
        Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

    Example 2:

        Input: n = 11111111111111111111111111111101
        Output:   3221225471 (10111111111111111111111111111111)
        Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

 

    Constraints:

        The input must be a binary string of length 32

    

    Follow up: If this function is called many times, how would you optimize it?

*/

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(n)
uint32_t n;
{
    uint32_t res = 0;
    
    while (n > 0)
    {
        res <<= 1;

        if(n & 1 == 1) res ^=1;
        n >>= 1;
    }
    return res;
}

uint32_t answer(n)
uint32_t n;
{
    uint32_t a = 0;
    for(int i = 0; i < 32; ++i){
        a <<= 1;
        a |= (1&n);
        n >>= 1;
    }
    return a;
}

void test_example1()
{
    uint32_t n = 0b00000010100101000001111010011100;
    uint32_t actual = answer(n);
    uint32_t expected = 0b00111001011110000010100101000000;

    printf(actual == expected ? "test case example1 PASS\n" : "test case example1 FAIL\n");
}

void test_example2()
{
    uint32_t n = 0b11111111111111111111111111111101;
    uint32_t actual = answer(n);
    uint32_t expected = 0b10111111111111111111111111111111;

    printf(actual == expected ? "test case example2 PASS\n" : "test case example2 FAIL\n");
}

/*

input: 00000010100101000001111010011100

output:     15065253 (00000000111001011110000010100101)



*/

int main()
{
    test_example1();
    test_example2();
    return 0;
}