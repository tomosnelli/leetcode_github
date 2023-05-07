/*
    112. Path Sum
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/* DFS approach */
bool hasPathSumDFS(struct TreeNode* root, int targetSum, int tempSum)
{
    if(!root){
        return false;
    }

    if(!root->left && !root->right){
        return (targetSum-root->val) == tempSum;
    }

    return hasPathSumDFS(root->left, targetSum, tempSum + root->val) || 
           hasPathSumDFS(root->right, targetSum, tempSum + root->val);
}

bool hasPathSum(struct TreeNode* root, int targetSum)
{
    return hasPathSumDFS(root, targetSum, 0);
}

// Test cases
void test_case1() {
    struct TreeNode n1 = {5, NULL, NULL};
    struct TreeNode n2 = {4, NULL, NULL};
    struct TreeNode n3 = {8, NULL, NULL};
    struct TreeNode n4 = {11, NULL, NULL};
    struct TreeNode n5 = {13, NULL, NULL};
    struct TreeNode n6 = {4, NULL, NULL};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n8 = {2, NULL, NULL};
    struct TreeNode n9 = {1, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;

    bool result = hasPathSum(&n1, 22);
    printf("Test Case 1: %s\n", result ? "PASSED" : "FAILED");
}

void test_case2() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};

    n1.left = &n2;

    bool result = hasPathSum(&n1, 1);
    printf("Test Case 2: %s\n", result ? "FAILED" : "PASSED");
}

void test_case3() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};

    n1.right = &n2;

    bool result = hasPathSum(&n1, 3);
    printf("Test Case 3: %s\n", result ? "PASSED" : "FAILED");
}

int main() {
    test_case1();
    test_case2();
    test_case3();

    return 0;
}