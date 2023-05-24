/*
    461. Hamming Distance
*/
#include <stdio.h>

int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int sum = 0;
    while(xored){
        if(n&0b1){
            ++sum;
        }
        n >>= 1;
    }
    return sum;
}