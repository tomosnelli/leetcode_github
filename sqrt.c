/*
    69. Sqrt(x)
*/
#include <stdio.h>

int mySqrt(int x){
    if(!x || x == 1) return x;

    int left = 1;
    int right = x;

    while(left <= right){
        int mid = left + (right - left) / 2;

        // perfect square
        if(mid == x / mid){
            return mid;
        } else if(mid < x/mid){
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }
    return right;
}
