/*
    61. Rotate List
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listlen(struct ListNode* head)
{
    int count = 0;
    while(head){
        head = head->next;
        ++count;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(!head || !head->next || k==0) return head;

    int length = listlen(head);
    int actual_k = k % length;

    if(length == k || actual_k == 0) return head;

    struct ListNode* current = head;
    struct ListNode* prev = head;

    for(int i = 1; i < length - actual_k + 1; ++i){
        prev = current;
        current = current->next;
    }

    prev->next = NULL;

    struct ListNode* temp = current;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = head;
    
    return current;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* createList(int arr[], int size) {
    struct ListNode* head = NULL;
    struct ListNode** current = &head;

    for (int i = 0; i < size; ++i) {
        *current = (struct ListNode*) malloc(sizeof(struct ListNode));
        (*current)->val = arr[i];
        (*current)->next = NULL;
        current = &((*current)->next);
    }

    return head;
}

void freeList(struct ListNode* head) {
    struct ListNode* tmp;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void test_case1() {
    printf("Test Case 1:\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    int k = 2;

    printf("Input list: ");
    printList(head);
    printf("Rotation value: %d\n", k);

    struct ListNode* rotated = rotateRight(head, k);
    printf("Output list: ");
    printList(rotated);

    freeList(rotated);
}

void test_case2() {
    printf("\nTest Case 2:\n");
    int arr[] = {0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    int k = 4;

    printf("Input list: ");
    printList(head);
    printf("Rotation value: %d\n", k);

    struct ListNode* rotated = rotateRight(head, k);
    printf("Output list: ");
    printList(rotated);

    freeList(rotated);
}

void test_case3() {
    printf("\nTest Case 3:\n");
    int arr[] = {1};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    int k = 0;

    printf("Input list: ");
    printList(head);
    printf("Rotation value: %d\n", k);

    struct ListNode* rotated = rotateRight(head, k);
    printf("Output list: ");
    printList(rotated);

    freeList(rotated);
}

void test_case4() {
    printf("\nTest Case 4:\n");
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    int k = 3;

    printf("Input list: ");
    printList(head);
    printf("Rotation value: %d\n", k);

    struct ListNode* rotated = rotateRight(head, k);
    printf("Output list: ");
    printList(rotated);

    freeList(rotated);
}

void test_case5() {
    printf("\nTest Case 5:\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    int k = 10;

    printf("Input list: ");
    printList(head);
    printf("Rotation value: %d\n", k);

    struct ListNode* rotated = rotateRight(head, k);
    printf("Output list: ");
    printList(rotated);

    freeList(rotated);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    return 0;
}
