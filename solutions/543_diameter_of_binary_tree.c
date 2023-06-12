/*
    543. Diameter of Binary Tree
*/
#include "../utils/common.h"

int getDepth(struct TreeNode* root){
    if(!root) return 0;
    
    int left = getDepth(root->left);
    int right = getDepth(root->right);

    return left > right ? left+1 : right+1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    if(!root) return 0;

    int left = getDepth(root->left);
    int right = getDepth(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    int diameter = left+ right;

    diameter = leftDiameter > diameter ? leftDiameter : diameter;
    diameter = rightDiameter > diameter ? rightDiameter : diameter;

    return diameter;
}