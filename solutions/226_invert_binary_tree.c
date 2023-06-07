/*
    226. Invert Binary Tree
*/
#include "../utils/common.h"

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root){
        return NULL;
    }

    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}