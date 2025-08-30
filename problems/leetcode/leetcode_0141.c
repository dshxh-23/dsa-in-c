/* LEET CODE #141: Linked List Cycle */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Solved using Floyd's Cycle Detection Algorithm (Tortoise and Hare Method)
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast -> next -> next;

        if(fast == slow) {
            return true;
        }
    }
    return false;
}