#ifndef DSA_LINKED_LIST_H
#define DSA_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct ll_node ll_node;

/**
 * @brief Creates a new node with the given data.
 * @param data The integer value to store in the node.
 * @return Pointer to the newly created node, or NULL if allocation fails.
 */
ll_node* ll_create_node(int data);

/**
 * @brief Inserts a new node at the beginning of the linked list.
 * @param headRef Pointer to the head pointer of the list.
 * @param data The integer value to insert.
 */
void ll_push_front(ll_node** headRef, int data);

/**
 * @brief Inserts a new node at the end of the linked list.
 * @param headRef Pointer to the head pointer of the list.
 * @param data The integer value to insert.
 */
void ll_push_back(ll_node** headRef, int data);

/**
 * @brief Inserts a new node at a specific position in the linked list (1-based index).
 * @param headRef Pointer to the head pointer of the list.
 * @param data The integer value to insert.
 * @param position The position (1-based) to insert the new node.
 */
void ll_insert_at(ll_node** headRef, int data, int position);

/**
 * @brief Deletes the node at the beginning of the linked list.
 * @param headRef Pointer to the head pointer of the list.
 */
void ll_pop_front(ll_node** headRef);

/**
 * @brief Deletes the node at the end of the linked list.
 * @param headRef Pointer to the head pointer of the list.
 */
void ll_pop_back(ll_node** headRef);

/**
 * @brief Deletes the node at a specific position in the linked list (1-based index).
 * @param headRef Pointer to the head pointer of the list.
 * @param position The position (1-based) of the node to delete.
 */
void ll_delete_at(ll_node** headRef, int position);

/**
 * @brief Searches for a key in the linked list.
 * @param head Pointer to the head of the list.
 * @param key The integer value to search for.
 * @return The position (1-based) of the key if found, -1 otherwise.
 */
int ll_search(ll_node* head, int key);

/**
 * @brief Displays the contents of the linked list.
 * @param head Pointer to the head of the list.
 */
void ll_display(ll_node* head);

/**
 * @brief Counts the number of nodes in the linked list.
 * @param head Pointer to the head of the list.
 * @return The number of nodes in the list.
 */
int ll_count_nodes(ll_node* head);


#endif