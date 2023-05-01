/*
    725. Split Linked List in Parts
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* Note: The returned array must be malloced, assume caller calls free(). */

int getLength(struct ListNode* head)
{
    int length = 0;
    struct ListNode* current = head;

    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

struct ListNode* split(struct ListNode** head, int size)
{
    // temp is for iterating over head
    if(*head == NULL) return NULL;
    struct ListNode* temp = *head;

    // temp_head is for returning the head
    // so that it can be added to the list
    struct ListNode* temp_head = *head;

    for(int i = 1; i < size; ++i){
        if(temp->next == NULL) break;
        temp = temp->next;
    }

    // change where head is pointing to
    *head = temp->next;
    temp->next = NULL;

    return temp_head;
}

struct ListNode** splitListToParts(
    struct ListNode* head,
    int k,
    int* returnSize
)
{
    struct ListNode** array = malloc(k * sizeof(struct ListNode*));
    int length = getLength(head);
    int extra_elements = length % k;

    for(int i = 0; i < k; ++i){
        int part_size = length / k + (i < extra_elements ? 1 : 0);
        array[i] = split(&head, part_size);
    }

    *returnSize = k;

    return array;
}

void printList(struct ListNode* head) {
    if (head == NULL) {
        printf("]");
        return;
    }

    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        temp = temp->next;
        if (temp != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

void printArrayOfLists(struct ListNode** array, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("[");
        printList(array[i]);
        printf("]");
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertNode(struct ListNode** head, int val) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void test_case1() {
    struct ListNode* head = NULL;
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);

    int k = 5;
    int returnSize;
    struct ListNode** result = splitListToParts(head, k, &returnSize);

    printArrayOfLists(result, k);

    // Free the allocated memory for the array
    free(result);
}

void test_case2() {
    struct ListNode* head = NULL;
    for (int i = 9; i > 0; --i) {
        insertNode(&head, i);
    }

    int k = 3;
    int returnSize;
    struct ListNode** result = splitListToParts(head, k, &returnSize);

    printArrayOfLists(result, k);

    // Free the allocated memory for the array
    free(result);
}

void test_case3() {
    struct ListNode* head = NULL;
    for (int i = 6; i > 0; --i) {
        insertNode(&head, i);
    }

    int k = 4;
    int returnSize;
    struct ListNode** result = splitListToParts(head, k, &returnSize);

    printArrayOfLists(result, k);

    // Free the allocated memory for the array
    free(result);
}

int main() {
    printf("Test Case 1:\n");
    test_case1();
    printf("\nTest Case 2:\n");
    test_case2();
    printf("\nTest Case 3:\n");
    test_case3();

    return 0;
}

