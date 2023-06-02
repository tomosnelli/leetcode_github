/*
    98. Validate Binary Search Tree
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

        The left
        subtree
        of a node contains only nodes with keys less than the node's key.
        The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.
 

    Example 1:

        Image: https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg
        Input: root = [2,1,3]
        Output: true


    Example 2:

        Image: https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg
        Input: root = [5,1,4,null,null,3,6]
        Output: false
        Explanation: The root node's value is 5 but its right child's value is 4.
    

    Constraints:

        The number of nodes in the tree is in the range [1, 10^4].
        -2^31 <= Node.val <= 2^31 - 1
*/
#define INT_MAX 9223372036854775807
#define INT_MIN -9223372036854775808

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

bool helper(root, max, min)
TreeNode *root;
long int max;
long int min;
{

    if (!root) return true;

    return (root->val < max && root->val > min)  && helper(root->left, root->val, min) && helper(root->right, max, root->val);

}

bool isValidBST(root)
TreeNode *root;
{

    return helper(root, INT_MAX, INT_MIN);

}


