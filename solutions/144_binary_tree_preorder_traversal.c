/*
    144. Binary Tree Preorder Traversal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode* root, int* returnSize, int* return_array)
{
    if(!root) return;

    // visit left subtree
    return_array[(*returnSize)++] = root->val;
    preorder(root->left, returnSize, return_array);
    preorder(root->right, returnSize, return_array);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* array = malloc(100 * sizeof(int));
    *returnSize = 0;

    preorder(root, returnSize, array);
    
    return array;
}
