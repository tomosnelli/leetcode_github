/*
    509. Fibonacci Number
*/
#include "../utils/common.h"

int fib(int n){
    int first = 0;
    int second = 1;

    if(n == 0) return 0;
    if(n == 1) return 1;

    for(int i = 2; i <= n; ++i){
        // fib(2) = fib(1) + fib(0)
        int sum = second + first;
        printf("sum: %d\n", sum);
        first = second;
        second = sum;
    }

    return second;
}

int main(){

    int fib_num = fib(3);
    printf("result: %d\n", fib_num);
    return 0;
}
