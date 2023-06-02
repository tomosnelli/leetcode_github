/*
    memo for how to make a deep copy of a linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_node(int val)
{
    struct ListNode* node = malloc(sizeof(struct ListNode));
    if(!node){
        perror("Memory Allocation Failed.\n");
        exit(1);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

void insert_node(struct ListNode** head, int val)
{
    struct ListNode* node = create_node(val);
    if(*head == NULL){
        *head = node;
    } else {
        struct ListNode* current = *head;
        while(current->next){
            current = current->next;
        }
        current->next = node;
    }
}

struct ListNode* copyRandomList(struct ListNode* head) {
    if(!head) return NULL;

    struct ListNode* node = create_node(head->data);

    node->next = copyRandomList(head->next);

    return node;
}