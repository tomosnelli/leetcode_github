/*
    106. Construct Binary Tree from Inorder and Postorder Traversal
    https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=study-plan-v2&envId=top-interview-150
*/
#include "../utils/common.h"

struct TreeNode* createTreeNode(int value){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left  = NULL;
    node->right = NULL;

    return node;
}

int find_target_index(int target, int* inorder, int inorderSize){
    for(int i = 0; i < inorderSize; ++i){
        if(inorder[i] == target){
            return i;
        }
    }

    return -1;
}

struct TreeNode* helper(
    int* inorder,
    int inorderSize,
    int* postorder,
    int postorderSize,
    int index
){
    if( index < 0 || postorderSize < index) return NULL;

    int targetIndex = find_target_index(postorder[index], inorder, inorderSize);
    if(targetIndex == -1) return NULL;

    struct TreeNode* root = createTreeNode(postorder[index]);

    int leftSize  = targetIndex;
    int rightSize = inorderSize - targetIndex - 1;

    root->left  = helper(inorder, leftSize, postorder, postorderSize, index-rightSize-1);
    root->right = helper(inorder+leftSize+1, rightSize, postorder, postorderSize, index-1);

    return root;
}

struct TreeNode* buildTree(
    int* inorder,
    int inorderSize,
    int* postorder,
    int postorderSize
){
    /*
        inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]

        first iteration

        left size = 1
        right size = 5 - 1 - 1 = 3


    */
    return helper(inorder, inorderSize, postorder, postorderSize, postorderSize-1);
}