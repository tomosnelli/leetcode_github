/*
    1721. Swapping Nodes in a Linked List
*/
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k)
{

    if(!head) return NULL;
    if(!head->next) return head;
    /* two pointer problem */
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;

    for(int i = 1; i < k; ++i){
        ptr2 = ptr2->next;
    }

    struct ListNode* left = ptr2;

    while(ptr2 && ptr2->next){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    int temp = ptr1->val;
    ptr1->val = left->val;
    left->val = temp;
    return head;
}