#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

bool helper(struct ListNode** left, struct ListNode* right)
{
    if(!right){
        return true;
    }

    bool boolean = helper(left, right->next);
    if(boolean == false) return false;

    bool current = (right->val == (*left)->val);

    *left = (*left)->next;

    return current;
}

bool isPalindrome(struct ListNode* head)
{
    return helper(&head, head);
}
