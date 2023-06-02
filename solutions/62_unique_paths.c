/*
    62. Unique Paths
*/
#include <stdio.h>
#include <assert.h>

// m -> tate, n -> yoko
// japanese input fails

/* dynamic programming approach */
int uniquePaths(int m, int n)
{
    int matrix[m][n];

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            matrix[i][j] = 1;
            if(0 <= i-1 && 0 <= j-1){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
    }

    return matrix[m-1][n-1];
}

void test_case1() {
    int result = uniquePaths(3, 2);
    assert(result == 3);
}

void test_case2() {
    int result = uniquePaths(7, 3);
    assert(result == 28);
}

void test_case3() {
    int result = uniquePaths(1, 1);
    assert(result == 1);
}

void test_case4() {
    int result = uniquePaths(4, 4);
    assert(result == 20);
}

void test_case5() {
    int result = uniquePaths(5, 5);
    assert(result == 70);
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