/*
    965. Univalued Binary Tree
*/
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode* root, int value)
{
    if(!root) return true;

    if(root->val != value) return false;

    return check(root->left, root->val) && check(root->right, root->val);
}

bool isUnivalTree(struct TreeNode* root)
{
    if(!root) return true;
    return check(root, root->val);
}