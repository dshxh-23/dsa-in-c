#include <stdio.h>
#include "linked_list.h"

int main(void) {

    printf("\n\n============================| LINKED LIST EXAMPLE |============================\n\n");

    ll_node* head = NULL;

    ll_push_back(&head, 10);
    ll_push_back(&head, 20);
    ll_push_back(&head, 30);
    ll_display(head);

    ll_push_front(&head, 5);
    ll_display(head);

    ll_insert_at(&head, 15, 3);
    ll_display(head);

    printf("Count: %d\n", ll_count_nodes(head));

    int key = 20;
    int pos = ll_search(head, key);
    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    ll_pop_front(&head);
    ll_display(head);

    ll_pop_front(&head);
    ll_display(head);

    ll_delete_at(&head, 2);
    ll_display(head);

    return 0;
}