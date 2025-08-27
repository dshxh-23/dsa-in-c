#ifndef DSA_STATIC_ARRAY_H
#define DSA_STATIC_ARRAY_H


#include <stddef.h>


/*
* Simple fixed-capacity integer array wrapper ("static array").
* Conventions follow your linked_list.c style: informative prints on error,
* functions return int status where appropriate, and allocation failures
* exit the program (mirrors ll_create_node behaviour).
*/

typedef struct static_array static_array;

// Create a static array of a given capacity
static_array* sa_create_array(size_t capacity);

// TO BE IMPLEMENTED LATER
// static_array* sa_create_array_from_buffer(int* buffer, size_t capacity);

// =--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=

// Insert element at a location 
int sa_insert_at(static_array* arr, size_t index, int val);

// Insert element at the begining of the array. If oth index is occupied, then shift all elements one step right. Returns 0 upon successful insertion else return -1 if you couldn't insert element.
int sa_insert_first(static_array* arr, int val);

// Insert element at the end of the array. Returns 0 if inserted successfully else return -1.
int sa_insert_last(static_array* arr, int val);

// Modify element - return 0 if operation performed successfully else return -1
int sa_modify_at(static_array* arr, size_t index, int val);

// =--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=

// Remove element at a specific location - Modify element - return 0 if operation performed successfully else return -1
int sa_remove_at(static_array* arr, size_t index);

// Remove first element and shift all elements to left - return 0 if operation performed successfully else return -1
int sa_remove_first(static_array* arr);

// Remove last element - Modify element - return 0 if operation performed successfully else return -1
int sa_remove_last(static_array* arr);

// =--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=

// Get first element
int sa_get_first(static_array* arr);

// Get last element
int sa_get_last(static_array* arr);

// Get specific element
int sa_get_element(static_array* arr, size_t index);

// =--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=

// Find specific element - returns index of that element (-1 if element not found)
int sa_find_val(static_array* arr, int val);

// =--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=

// Get the current no. of elements
int sa_count_elements(static_array* arr, int val);  

// Display the array
void sa_display(static_array* arr);

// Delete entire array
void sa_free(static_array* arr);






// /* Create a new static array with given capacity. Exits on allocation failure. */
// static_array* sa_create(size_t capacity);
// /* Initialize wrapper around external buffer. Does NOT take ownership. */
// static_array* sa_init_with_buffer(int *buffer, size_t capacity);


// /* Set value at index. Returns 0 on success, -1 on error (out of range). */
// int sa_set(static_array *arr, size_t index, int value);


// /* Get value at index. Returns 0 on success and writes into *out; -1 on error. */
// int sa_get(const static_array *arr, size_t index);


// /* Insert value at index (shifts elements to the right).
// * Returns 0 on success, -1 on error (index > size or full).
// */
// int sa_insert_at(static_array *arr, size_t index, int value);


// /* Remove value at index (shifts elements left). If out != NULL, stores removed value. */
// int sa_remove_at(static_array *arr, size_t index);


// /* Push value at the end. Returns 0 on success, -1 if full. */
// int sa_push_back(static_array *arr, int value);


// /* Pop last value. Returns 0 on success and writes into *out; -1 if empty. */
// int sa_pop_back(static_array *arr);


// /* Current number of elements */
// size_t sa_size(const static_array *arr);


// /* Print contents to stdout (for examples/debug) */
// void sa_display(const static_array *arr);


// /* Free resources (only frees the internal buffer if sa owns it). */
// void sa_free(static_array *arr);





#endif /* STATIC_ARRAYS_H */