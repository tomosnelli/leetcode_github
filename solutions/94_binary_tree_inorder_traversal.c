/*
    94. Binary Tree Inorder Traversal
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void helper(struct TreeNode* node, int* returnSize, int* array)
{
    if(node->left) helper(node->left, returnSize, array);
    array[(*returnSize)++] = node->val;
    if(node->right) helper(node->right, returnSize, array);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* array = malloc(sizeof(int) * 100);

    if(root){
        helper(root, returnSize, array);
    }

    return array;
}
