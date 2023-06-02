/*
    160. Intersection of Two Linked Lists
*/
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int lllen(struct ListNode* head)
{
    int count = 0;
    while(head){
        head = head->next;
        ++count;
    }
    return count;
}

/*
//one way of going about it is a two pass solution

//this was very slow

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int length = lllen(headA);
    struct ListNode* array[length];

    for(int i = 0; headA && i < length; ++i){
        array[i] = headA;
        headA = headA->next;
    } 

    while(headB){
        for(int i = 0; i < length; ++i){
            if(array[i] == headB){
                return headB;
            }
        }
        headB = headB->next;
    }

    return NULL;
}
*/

/* fast solution */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode* a = headA;
    struct ListNode* b = headB;

    while(a != b){
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}