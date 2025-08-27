/* LEET CODE #237: Delete Node in a Linked List */

struct ListNode {
   int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode* temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(temp);
}