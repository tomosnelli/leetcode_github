/* 
    19. Remove Nth Node From ENd of List
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* left = &dummy;
    struct ListNode* right = &dummy;

    for(int i = 0; i <= n; ++i){
        right = right->next;
    }

    while(right){
        left = left->next;
        right = right->next;
    }

    struct ListNode* to_be_deleted = left->next;
    left->next = left->next->next;
    free(to_be_deleted);

    return dummy.next;
}