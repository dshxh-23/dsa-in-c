#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node** headRef, int data);
void insertAtEnd(Node** headRef, int data);
void insertAtPosition(Node** headRef, int data, int position);
void deleteAtBeginning(Node** headRef);
void deleteAtEnd(Node** headRef);
void deleteAtPosition(Node** headRef, int position);
int search(Node* head, int key);
void display(Node* head);
int countNodes(Node* head);

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Insert at end
void insertAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at specific position (1-based index)
void insertAtPosition(Node** headRef, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(headRef, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *headRef;
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
void deleteAtBeginning(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

// Delete at end
void deleteAtEnd(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    Node* temp = *headRef;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete at specific position
void deleteAtPosition(Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(headRef);
        return;
    }
    Node* temp = *headRef;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

// Search an element
int search(Node* head, int key) {
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
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


// Driver code (for quick testing)
int main() {

    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);

    insertAtBeginning(&head, 5);
    display(head);

    insertAtPosition(&head, 15, 3);
    display(head);

    printf("Count: %d\n", countNodes(head));

    int key = 20;
    int pos = search(head, key);
    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    deleteAtBeginning(&head);
    display(head);

    deleteAtEnd(&head);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    return 0;
}