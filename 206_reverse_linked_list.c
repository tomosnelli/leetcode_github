/*
* 206. Reverse Linked List
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if(!head){
        return NULL;
    }

    if(!head->next){
        return head;
    }

    struct ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}