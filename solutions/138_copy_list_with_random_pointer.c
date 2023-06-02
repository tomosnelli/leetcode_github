/*
    138. Copy List with Random Pointer
*/
#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    // Step 1: Create a new copy of each node and insert it after the original node
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* copy = createNode(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // Step 2: Update the random pointers of the copied nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // Step 3: Separate the original and copied nodes into two separate lists
    curr = head;
    struct Node* newHead = head->next;
    struct Node* newCurr = newHead;
    while (curr != NULL) {
        curr->next = curr->next->next;
        if (newCurr->next != NULL) {
            newCurr->next = newCurr->next->next;
        }
        curr = curr->next;
        newCurr = newCurr->next;
    }
    
    return newHead;
}
