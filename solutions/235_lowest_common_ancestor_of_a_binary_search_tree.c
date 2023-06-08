/*
    235. Lowest Common Ancestor of a Binary Search Tree
*/
#include "../utils/common.h"

struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q
)
{
    if(!root) return NULL;

    if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }

    if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    if((p->val < root->val && q->val > root->val)
            ||
        (p->val > root->val && q->val < root->val) 
    ){
        return root;
    }

    if(p->val == root->val){
        return p;
    }

    if(q->val == root->val){
        return q;
    }

    return root;
}