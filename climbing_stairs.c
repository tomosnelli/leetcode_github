/*
    70. Climbing Stairs
*/

#include <stdio.h>
#include <assert.h>

/* recursive
int climbStairs(int n)
{
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    return climbStairs(n-2) + climbStairs(n-1);
}
*/

int climbStairs(int n)
{

    if(n == 1){
        return n;
    }

    int array[n+1];

    // fill in base case
    array[0] = 1;
    array[1] = 1;
    for(int i = 2; i <= n; ++i){
        array[i] = array[i-1] + array[i-2];
    }
    return array[n];
}

int optimal(int n){
    int n1 = 1, n2 = 2;

    if(n==1) return n1;
    if(n==2) return n2;

    for(int i = 2; i < n; ++i){
        int temp = n2;
        n2 += n1;
        n1 = temp;
    }

    return n2;
}

void test_case1() {
    int result = climbStairs(1);
    assert(result == 1);
}

void test_case2() {
    int result = climbStairs(2);
    assert(result == 2);
}

void test_case3() {
    int result = climbStairs(3);
    assert(result == 3);
}

void test_case4() {
    int result = climbStairs(4);
    assert(result == 5);
}

void test_case5() {
    int result = climbStairs(5);
    assert(result == 8);
}

void test_case6() {
    int result = climbStairs(10);
    assert(result == 89);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    test_case6();
    printf("All test cases passed!\n");
    return 0;
}