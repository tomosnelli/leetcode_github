#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H 

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/* Binary Tree */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Linked List */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Linked List Function */
struct ListNode* createNode(int val);
void insert_node(struct ListNode** head, int val);

/* Hash Table */
/*
*********************************************
    this can vary from case to case,
    so it will not be in commons header file
*********************************************
*/
/*
typedef struct
{
    int val;
    UT_hash_handle hh;
} HashTable;
*/

/* qsort function */
/*
***********************************************
    This function needs to be present in the
    code section that will be submitted.
    Thus it doesn't make sense to keep it here
***********************************************
/*
int compare_int(const void* a, const void* b);
*/

#endif