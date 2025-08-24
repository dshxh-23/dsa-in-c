#include <stdio.h>
#include "linked_list.h"

int main(void) {

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