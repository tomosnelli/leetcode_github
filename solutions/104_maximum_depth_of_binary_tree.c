/*
    104. Maxium Depth of Binary Tree
*/
#include "../utils/common.h"

int maxDepth(struct TreeNode* root)
{
    if(!root) return 0;

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    return left > right ? left : right;
}

void test_case1() {
    // Test case with a single node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = NULL;

    int depth = maxDepth(root);
    printf("Test Case 1: Expected Depth = 1, Calculated Depth = %d\n", depth);
}

void test_case2() {
    // Test case with a balanced binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    int depth = maxDepth(root);
    printf("Test Case 2: Expected Depth = 3, Calculated Depth = %d\n", depth);
}

void test_case3() {
    // Test case with an unbalanced binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = NULL;
    root->right = NULL;

    int depth = maxDepth(root);
    printf("Test Case 3: Expected Depth = 3, Calculated Depth = %d\n", depth);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    return 0;
}