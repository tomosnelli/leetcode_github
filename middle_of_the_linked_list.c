/*
    876. Middle of the Linked List
*/
#include <stdio.h>



int getLength(struct ListNode* head)
{
    int count = 0;
    while(head){
        head = head->next;
        ++count;
    }
    return count;
}

// my slow solution

/*
struct ListNode* middleNode(struct ListNode* head)
{
    int lllen = getLength(head);
    if(lllen == 1) return head;

    for(int i = 1; i < lllen/2 + 1; ++i) head = head->next;
    return head;
}
*/

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow_ptr = head;
    struct ListNode* fast_ptr = head;

    while((fast_ptr != NULL)&&(fast_ptr->next != NULL)){
        slow_ptr = slow_ptr->next;
        if(fast_ptr->next->next){
            fast_ptr = fast_ptr->next->next;
        } else {
            fast_ptr = fast_ptr->next;
        }
    }
    return slow_ptr;
}