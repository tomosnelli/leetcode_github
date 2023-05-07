/*
    101. Symmetric Tree
*/
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetricDFS(struct TreeNode* left, struct TreeNode* right)
{
    if(!left && !right){
        return true;
    }

    if(!left || !right){
        return false;
    }

    if(left->val != right->val){
        return false;
    }

    return isSymmetricDFS(left->right, right->left) && isSymmetricDFS(left->left, right->right);
}

/* depth first search approach */
bool isSymmetric(struct TreeNode* root){
    if(!root){
        return true;
    }

    if(!root->left && !root->right){
        return true;
    }

    return isSymmetricDFS(root->left, root->right);
}

void test_case1() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {2, NULL, NULL};
    n1.left = &n2;
    n1.right = &n3;
    assert(isSymmetric(&n1) == true);
}

void test_case2() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {2, NULL, NULL};
    struct TreeNode n4 = {3, NULL, NULL};
    struct TreeNode n5 = {4, NULL, NULL};
    struct TreeNode n6 = {4, NULL, NULL};
    struct TreeNode n7 = {3, NULL, NULL};
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;
    n4.left = &n6;
    n5.right = &n7;
    assert(isSymmetric(&n1) == false);
}

void test_case3() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {2, NULL, NULL};
    struct TreeNode n4 = {3, NULL, NULL};
    struct TreeNode n5 = {3, NULL, NULL};
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.right = &n5;
    assert(isSymmetric(&n1) == true);
}

void test_case4() {
    assert(isSymmetric(NULL) == true);
}

void test_case5() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    n1.left = &n2;
    n1.right = &n3;
    assert(isSymmetric(&n1) == false);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    printf("All test cases passed.\n");
    return 0;
}
