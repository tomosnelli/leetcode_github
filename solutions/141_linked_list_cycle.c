/*
    141. Linked List Cycle
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode* Node;

void print_linked_list(Node head){
    if(!head->next){
        printf("%d\n", head->val);
        return;
    }
    printf("%d->", head->val);
    print_linked_list(head->next);
}

Node createNode(int assign_val){
    Node node = (Node) malloc(sizeof(struct ListNode));
    if(!node){
        perror("Memory Allocation Error");
        exit(1);
    }
    node->val = assign_val;
    node->next = NULL;
    return node;
}

Node createNodeWithNext(int assign_val, Node next){
    Node node = createNode(assign_val);
    node->next = next;
    return node;
}

void push(Node *head, int assign_val){
    Node newHead = createNodeWithNext(assign_val, *head);
    *head = newHead;
}

void freeLinkedList(Node head){
    Node temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeLinkedListCycle(Node head, int size){
    int start = 0;
    Node temp;

    while(start < size){
        temp = head;
        head = head->next;
        free(temp);
        ++start;
    }
}

void makeCycle(Node head){
    int count = 0;
    Node node3;
    while(head->next){
        if(count == 2){
            node3 = head;
        }
        ++count;
    }
    head->next = node3;
}

int hasCycle(Node head) {
    if(!head){
        return false;
    }

    Node slow = head;
    Node fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node head = createNode(5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    makeCycle(head);

    int val = hasCycle(head);
    //freeLinkedList(head);
    freeLinkedListCycle(head, 5);

    printf("has cycle? %s\n", val == 1 ? "TRUE": "FALSE");
    return 0;
}