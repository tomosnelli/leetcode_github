/*
    105. Construct Binary Tree from Preorder and Inorder Traversal
*/
#include "../utils/common.h"


/*
    Inorder Traversal
    
    void inord_traverse(root){
        inord_traverse(root->left)
        visit(root)
        inord_traverse(root->right)
    }


    Preorder Traversal

    void preord_traverse(root){
        visit(root)
        preord_traverse(root->left)
        preord_traverse(root->right)
    }


    preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    head of preorder will be root
*/

struct TreeNode* createTreeNode(int val){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
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
    int* preorder,
    int preorderSize,
    int* inorder,
    int inorderSize,
    int index
){
    if(index < 0 || preorderSize <= index) return NULL;
    
    // set up root node
    int target_index = find_target_index(preorder[index], inorder, inorderSize);
    if(target_index == -1) return NULL;

    struct TreeNode* root = createTreeNode(preorder[index]);

    int left_size = target_index;
    int right_size = inorderSize - target_index - 1;

    root->left  = helper(preorder, preorderSize, inorder, left_size, index+1);
    root->right = helper(preorder, preorderSize, inorder + target_index + 1, right_size, index+1+left_size);

    return root;
}

struct TreeNode* buildTree(
    int* preorder,
    int preorderSize,
    int* inorder,
    int inorderSize
){
    return helper(preorder, preorderSize, inorder, inorderSize, 0);
}