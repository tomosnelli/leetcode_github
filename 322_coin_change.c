/*
    322. Coin Change
*/
#include <stdio.h>
#include <assert.h>

int coinChange(int* coins, int coinsSize, int amount)
{
    int array[amount+1];
    array[0] = 0;
    for(int i = 1; i <= amount; ++i){
        array[i] = amount+1;
        for(int j = 0; j < coinsSize; ++j){
            if(coins[j] <= i)
                array[i] =
                    array[i] > (array[i-coins[j]] + 1) ?
                    array[i-coins[j]] + 1 : array[i];
        }
    }
    if(array[amount] > amount) return -1;
    return array[amount];
}

void test_case1() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int expected = 3; // 5 + 5 + 1
    int result = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    printf("result: %d\n", result);
    assert(result == expected);
}

void test_case2() {
    int coins[] = {2};
    int amount = 3;
    int expected = -1; // Not possible to make change for the given amount
    int result = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    printf("result: %d\n", result);
    assert(result == expected);
}

void test_case3() {
    int coins[] = {1, 4, 5};
    int amount = 8;
    int expected = 2; // 4 + 4
    int result = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    assert(result == expected);
}

void test_case4() {
    int coins[] = {3, 5, 7};
    int amount = 26;
    int expected = 4; // 7 + 7 + 7 + 5
    int result = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    assert(result == expected);
}

void test_case5() {
    int coins[] = {186, 419, 83, 408};
    int amount = 6249;
    int expected = 20;
    int result = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    assert(result == expected);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();

    printf("All test cases passed!\n");
    return 0;
}