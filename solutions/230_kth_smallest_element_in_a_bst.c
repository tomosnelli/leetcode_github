/*
    230. Kth Smallest Element in a BST
*/
#include "../utils/common.h"

int inorderTraversal(struct TreeNode* root, int k, int* visit_count)
{
    if(root->left){
        int result = inorderTraversal(root->left, k, visit_count);
        if(result != -1) return result;
    }

    // visit
    ++(*visit_count);
    if(k == *visit_count) return root->val;

    if(root->right){
        int result = inorderTraversal(root->right, k, visit_count);
        if(result != -1) return result;
    }

    return -1;
}

int kthSmallest(struct TreeNode* root, int k){
    int visit_count = 0;
    return inorderTraversal(root, k, &visit_count);
}