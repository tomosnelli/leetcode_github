/*
    21. Merge Two Sorted Lists
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode()
{
    struct ListNode* node = malloc(sizeof(struct ListNode));
    if(!node){
        printf("Allocation Error\n");
        exit(1);
    }
    node->val = INT_MAX;
    node->next = NULL;

    return node;
}

// my slow implementation
/*
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    // new linked list to merge into
    struct ListNode* head = createNode();
    struct ListNode* ptr = head;

    if(!list1 && list2){
        ptr->next = list2;
        return ptr->next;
    }

    if(list1 && !list2){
        ptr->next = list1;
        return ptr->next;
    }

    while(list1 && list2){
        if(list1->val < list2->val){
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }

    // either one of them is NULL
    if(list1){
        ptr->next = list1;
    }

    if(list2){
        ptr->next = list2;
    }

    struct ListNode* result = head->next;
    free(head);
    return result;
}
*/

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct ListNode* head)
{
    struct ListNode* temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1; 
    } else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

void test_case1() {
    struct ListNode* list1 = createNode();
    list1->val = 1;
    list1->next = createNode();
    list1->next->val = 3;
    list1->next->next = createNode();
    list1->next->next->val = 5;

    struct ListNode* list2 = createNode();
    list2->val = 2;
    list2->next = createNode();
    list2->next->val = 4;
    list2->next->next = createNode();
    list2->next->next->val = 6;

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Test Case 1:\n");
    printList(merged);
    freeLinkedList(merged);

}

void test_case2() {
    struct ListNode* list1 = NULL;

    struct ListNode* list2 = createNode();
    list2->val = 1;
    list2->next = createNode();
    list2->next->val = 3;
    list2->next->next = createNode();
    list2->next->next->val = 5;

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Test Case 2:\n");
    printList(merged);
    freeLinkedList(merged);
}

void test_case3() {
    struct ListNode* list1 = createNode();
    list1->val = 1;
    list1->next = createNode();
    list1->next->val = 3;
    list1->next->next = createNode();
    list1->next->next->val = 5;

    struct ListNode* list2 = NULL;

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Test Case 3:\n");
    printList(merged);
    freeLinkedList(merged);
}

void test_case4() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Test Case 4:\n");
    printList(merged);
    freeLinkedList(merged);
}

void test_case5() {
    struct ListNode* list1 = createNode();
    list1->val = 5;

    struct ListNode* list2 = createNode();
    list2->val = 1;
    list2->next = createNode();
    list2->next->val = 2;
    list2->next->next = createNode();
    list2->next->next->val = 3;

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Test Case 5:\n");
    printList(merged);
    freeLinkedList(merged);
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();

    return 0;
}