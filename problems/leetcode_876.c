/* 
LEET CODE 876: Middle of the Linked List
*/

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int getElements(struct ListNode* head) {
    int count = 0;
    struct ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

struct ListNode* middleNode(struct ListNode* head) {
    int count = getElements(head);
    struct ListNode* temp = head;
    if(count%2 == 0) {
        for(int i = 0; i<(count+2)/2; i++) {
            temp = temp->next;
        }
    } else {
        for(int i=0; i<(count/2)+1; i++) {
            temp = temp->next;
        }
    }
    return temp;
}