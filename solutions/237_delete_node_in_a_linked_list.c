/*
    237. Delete Node in a Linked List
*/
#include "../utils/common.h"

// slow
// void deleteNode(struct ListNode* node)
// {
//     while(node->next->next){
//         node->val = node->next->val;
//         node = node->next;
//     }
// 
//     node->val = node->next->val;
//     free(node->next);
//     node->next = NULL;
// }

//fast
void deleteNode(struct ListNode* node){
    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    temp->next = NULL;
    free(temp);
}