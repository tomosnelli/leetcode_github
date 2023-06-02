/*
    100. Same Tree
*/
#include <stdio.h>
#include <bool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p && !q) || (!p && q){
        return false;
    }

    if(!p && !q){
        return true;
    }

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    TreeNode p = TreeNode(val=1, left=TreeNode(val=2), right=TreeNode(val=3))
    TreeNode q = TreeNode(val=1, left=TreeNode(val=2), right=TreeNode(val=3))

    return 0;
}