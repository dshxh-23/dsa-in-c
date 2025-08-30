/* QUESTION
Provided the head of a linked list, reverse the entire list and return the head of the new reversed link list
*/

/* =--=--=--=--=--=--=--=--=--=--=--=--=--= STARTER CODE =--=--=--=--=--=--=--=--=--=--=--=--=--= */

#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node {
    int data;
    struct ll_node* next;
} ll_node;

// Create a new node
ll_node* ll_create_node(int data) {
    ll_node* newNode = (ll_node*) malloc(sizeof(ll_node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void ll_push_back(ll_node** headRef, int data) {
    ll_node* newNode = ll_create_node(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    ll_node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void ll_display(ll_node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    ll_node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* =--=--=--=--=--=--=--=--=--=--=--=--=--= WRITE CODE HERE =--=--=--=--=--=--=--=--=--=--=--=--=--= */

ll_node* reverse_ll(ll_node* head) {
    if(head->next == NULL) {
        return head;
    }
    
    ll_node* newNode = reverse_ll(head->next);
    
    
}



/* =--=--=--=--=--=--=--=--=--=--=--=--=--= TEST CODE =--=--=--=--=--=--=--=--=--=--=--=--=--= */


// WRITE TEST CODE HERE
int main() {
    ll_node* head = ll_create_node(0);
    ll_push_back(&head, 1);
    ll_push_back(&head, 2);
    ll_push_back(&head, 3);
    ll_push_back(&head, 4);
    ll_push_back(&head, 5);
    ll_push_back(&head, 6);
    ll_push_back(&head, 7);
    ll_push_back(&head, 8);
    ll_push_back(&head, 9);

    ll_display(reverse_ll(head));

}