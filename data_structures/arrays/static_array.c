#include "static_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct static_array {
	int* data;
	size_t capacity;
	size_t size;
	int owns_buffer;
} static_array;


static_array* sa_create_array(size_t capacity) {
    // Validate input parameter: capacity
	if (capacity == 0) {
		printf("Requested capacity must be > 0\n");
		return NULL;
	}

    // Memory allocation: static_array struct
	static_array* arr = (static_array*) malloc(sizeof(static_array));
	
    // Handling memory allocation failure: arr
    if (!arr) {
		printf("Memory allocation failed: couldn't allocate memory for the struct static_array!\n");
		exit(1);
	}

    // Memory allocation: array->data
	arr->data = (int*) malloc(sizeof(int) * capacity);

    // Handling memory allocation failure: arr->data
	if (!arr->data) {
		printf("Memory allocation failed: couldn't allocate memory for %zu integers in the array\n", capacity);
		free(arr);
		exit(1);
	}

    // Initialize struct members
	arr->capacity = capacity;
	arr->size = 0;
	arr->owns_buffer = 1;
	return arr;
}


int sa_insert_at(static_array* arr, size_t index, int val) {

	// Validate input parameter: arr
	if (!arr) {
		printf("sa_insert_at: NULL array pointer\n");
		return -1;
	}

	// Validate input parameter: index
	if (index > arr->size) {
		printf("sa_insert_at: index out of range (index=%zu, size=%zu)\n", index, arr->size);
		return -1;
	}

	// Check if array is full
	if (arr->size >= arr->capacity) {
		printf("sa_insert_at: array is full (capacity=%zu)\n", arr->capacity);
		return -1;
	}

	// Shift elements to make space for new value
	if (index < arr->size) {
		memmove(&arr->data[index + 1], &arr->data[index], (arr->size - index) * sizeof(int));
	}

	// Insert value and update size
	arr->data[index] = val;
	arr->size++;
	return 0;
}


int sa_insert_first(static_array* arr, int val) {
	// Insert value at the first position
	return sa_insert_at(arr, 0, val);
}


int sa_insert_last(static_array* arr, int val) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_insert_last: NULL array pointer\n");
		return -1;
	}
    
	// Check if array is full
	if (arr->size >= arr->capacity) {
		printf("sa_insert_last: array is full (capacity=%zu)\n", arr->capacity);
		return -1;
	}

	// Insert value at the last position and update size
	arr->data[arr->size++] = val;
	return 0;
}

int sa_modify_at(static_array* arr, size_t index, int val) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_modify_at: NULL array pointer\n");
		return -1;
	}

	// Validate input parameter: index
	if (index >= arr->size) {
		printf("sa_modify_at: index out of range (index=%zu, size=%zu)\n", index, arr->size);
		return -1;
	}

	// Modify value at the given index
	arr->data[index] = val;
	return 0;
}

int sa_remove_at(static_array* arr, size_t index) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_remove_at: NULL array pointer\n");
		return -1;
	}

	// Validate input parameter: index
	if (index >= arr->size) {
		printf("sa_remove_at: index out of range (index=%zu, size=%zu)\n", index, arr->size);
		return -1;
	}

	// Shift elements to remove value at index
	if (index + 1 < arr->size) {
		memmove(&arr->data[index], &arr->data[index + 1], (arr->size - index - 1) * sizeof(int));
	}

	// Update size
	arr->size--;
	return 0;
}

int sa_remove_first(static_array* arr) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_remove_first: NULL array pointer\n");
		return -1;
	}

	// Check if array is empty
	if (arr->size == 0) {
		printf("sa_remove_first: array is empty\n");
		return -1;
	}

	// Remove first element
	return sa_remove_at(arr, 0);
}

int sa_remove_last(static_array* arr) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_remove_last: NULL array pointer\n");
		return -1;
	}

	// Check if array is empty
	if (arr->size == 0) {
		printf("sa_remove_last: array is empty\n");
		return -1;
	}

	// Remove last element and update size
	arr->size--;
	return 0;
}

int sa_get_first(static_array* arr) {
	// Validate input parameter: arr and check if array is empty
	if (!arr || arr->size == 0) {
		printf("sa_get_first: array is empty or NULL\n");
		return -1;
	}

	// Return first element
	return arr->data[0];
}

int sa_get_last(static_array* arr) {
	// Validate input parameter: arr and check if array is empty
	if (!arr || arr->size == 0) {
		printf("sa_get_last: array is empty or NULL\n");
		return -1;
	}
    
	// Return last element
	return arr->data[arr->size - 1];
}

int sa_get_element(static_array* arr, size_t index) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_get_element: NULL array pointer\n");
		return -1;
	}

	// Validate input parameter: index
	if (index >= arr->size) {
		printf("sa_get_element: index out of range (index=%zu, size=%zu)\n", index, arr->size);
		return -1;
	}
    
	// Return element at index
	return arr->data[index];
}

int sa_find_val(static_array* arr, int val) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_find_val: NULL array pointer\n");
		return -1;
	}

	// Search for value in array
	for (size_t i = 0; i < arr->size; ++i) {
		if (arr->data[i] == val) return (int)i;
	}

	// Value not found
	return -1;
}

int sa_count_elements(static_array* arr, int val) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_count_elements: NULL array pointer\n");
		return 0;
	}

	// Count occurrences of value in array
	int count = 0;
	for (size_t i = 0; i < arr->size; ++i) {
		if (arr->data[i] == val) count++;
	}

	return count;
}

void sa_display(static_array* arr) {
	// Validate input parameter: arr
	if (!arr) {
		printf("sa_display: NULL array pointer\n");
		return;
	}

	// Display array elements
	printf("[");
	for (size_t i = 0; i < arr->size; ++i) {
		printf("%d", arr->data[i]);
		if (i + 1 < arr->size) printf(", ");
	}
	printf("] (size=%zu, capacity=%zu)\n", arr->size, arr->capacity);
}

void sa_free(static_array* arr) {
	// Validate input parameter: arr
	if (!arr) return;

	// Free array data if owned
	if (arr->owns_buffer && arr->data) free(arr->data);

	// Free struct
	free(arr);
}