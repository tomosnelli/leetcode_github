/*
    2. Add Two Numbers
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_list_node(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head_sum = create_list_node(0);
    struct ListNode* ptr = head_sum;

    while(l1 || l2){
        int l1_sum = 0, l2_sum=0;

        if(l1){
            l1_sum = l1->val;
            l1 = l1->next;
        }
        if(l2){
            l2_sum = l2->val;
            l2 = l2->next;
        }

        int temp = l1_sum + l2_sum + ptr->val;

        ptr->val = temp%10;

        if(l1 || l2 || temp/10){
            ptr->next = create_list_node(temp/10);
            ptr = ptr->next;
        }
    }

    return head_sum;
}

struct ListNode* optimal(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result = NULL;
    struct ListNode **ptr = &result;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry > 0){
        int sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        *p = malloc(sizeof(struct ListNode));
        (*p)->val = sum % 10;
        (*p)->next = NULL;
        p = &((*p)->next);
        carry = sum / 10;
    }
    return result;
}

void print_list(struct ListNode* node) {
    while (node) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode* node) {
    while (node != NULL) {
        struct ListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    // Test Case: l1 = [2, 4, 9], l2 = [5, 6, 4, 9]
    struct ListNode* l1 = create_list_node(2);
    l1->next = create_list_node(4);
    l1->next->next = create_list_node(9);

    struct ListNode* l2 = create_list_node(5);
    l2->next = create_list_node(6);
    l2->next->next = create_list_node(4);
    l2->next->next->next = create_list_node(9);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Test Case (l1 = [2, 4, 9], l2 = [5, 6, 4, 9]): ");
    print_list(result); // Expected output: 7 -> 0 -> 4 -> 0 -> 1

    free_list(l1);
    free_list(l2);
    free_list(result);

    return 0;
}
