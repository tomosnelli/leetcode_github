/*
    230. Kth Smallest Element in a BST
*/
#include "../utils/common.h"

/* Combinarion of inorder traversal and visit count
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
*/

// fast
void inorderTraversal(struct TreeNode* root, int* values, int* index){
    if(root == NULL) return;

    inorderTraversal(root->left, values, index);
    values[*index] = root->val;
    *index += 1;
    inorderTraversal(root->right, values, index);
}

int kthSmallest(struct TreeNode* root, int k){
    int index = 0;
    int* array = malloc(10000 * sizeof(int));
    inorderTraversal(root, array, &index);
    return array[k-1];
}