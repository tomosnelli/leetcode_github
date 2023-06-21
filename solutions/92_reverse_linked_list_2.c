/*
    92. Reverse Linked List 2
*/
#include "../utils/common.h"

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(head == NULL || left >= right)
        return head;
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    for(int i = 1; i < left; ++i){
        if(prev == NULL)
            return head;
        prev = prev->next;
    }

    struct ListNode* curr = prev->next;
    struct ListNode* next,* temp;
    for(int i = 0; i < right - left; ++i){
        if(curr == NULL)
            return head;
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy.next;
}
