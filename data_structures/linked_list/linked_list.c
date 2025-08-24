#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// Node structure 14
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

// Insert at beginning
void ll_push_front(ll_node** headRef, int data) {
    ll_node* newNode = ll_create_node(data);
    newNode->next = *headRef;
    *headRef = newNode;
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

// Insert at specific position (1-based index)
void ll_insert_at(ll_node** headRef, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        ll_push_front(headRef, data);
        return;
    }
    ll_node* newNode = ll_create_node(data);
    ll_node* temp = *headRef;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void ll_pop_front(ll_node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    ll_node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

// Delete at end
void ll_pop_back(ll_node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    ll_node* temp = *headRef;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete at specific position
void ll_delete_at(ll_node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        ll_pop_front(headRef);
        return;
    }
    ll_node* temp = *headRef;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    ll_node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

// Search an element
int ll_search(ll_node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1; // Not found
}

// Display linked list
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

// Count nodes
int ll_count_nodes(ll_node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}