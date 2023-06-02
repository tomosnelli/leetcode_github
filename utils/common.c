#include "common.h"

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

/*
int compare_int(const void* a, const void* b)
{
    return (*(int*) a - *(int*) b);
}
*/