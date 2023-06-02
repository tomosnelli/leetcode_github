#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(val)
int val;
{
    struct ListNode* ptr = malloc(sizeof(struct ListNode));
    ptr->val = val;
    return ptr;
}

struct ListNode* createNodeWithNext(val, next)
int val;
struct ListNode* next;
{
    struct ListNode* ptr = malloc(sizeof(struct ListNode));
    ptr->val = val;
    ptr->next = next;
    return ptr;
}

void push(head)
struct ListNode* head;
{
    struct ListNode* newHead = createNodeWithNext()
}

/*
void push(head)
struct ListNode* head;
{
    
}
*/

struct ListNode* reverse(head)
struct ListNode* head;
{
    if(!head) return NULL;

    if(!head->next) return head;

    struct ListNode *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

/*
struct ListNode* createLinkedList(number_of_nodes)
int number_of_nodes;
{
    node1
}
*/

int main()
{
    struct ListNode* ptr = createNode(2);
    struct ListNode* ptr2 = createNodeWithNext(1, ptr);
    printf("%d\n", ptr->val);
    printf("%d\n", ptr2->val);
    free(ptr);
    free(ptr2);
    return 0;
}