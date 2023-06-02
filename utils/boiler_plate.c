/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

int main()
{
    return 0;
}

#include "uthash.h"
typedef struct
{
    int val;
    UT_hash_handle hh;
} HashTable;
