/* LEET CODE #206: Reverse Linked List */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL || head->next == NULL) {return head;}

    struct ListNode* temp1 = head;
    struct ListNode* temp2 = head->next;
    struct ListNode* temp3 = head->next->next;

    temp1->next = NULL;

    while(temp3 != NULL) {
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }
    
    temp2->next = temp1;
    return temp2;
}