
#include "static_array.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("\n\n============================| ARRAY EXAMPLE |============================\n\n");

	// Create a static array with capacity 5
	static_array* arr = sa_create_array(5);
	if (!arr) {
		printf("Failed to create static array.\n");
		return 1;
	}

	// Insert elements
	sa_insert_last(arr, 10);
	sa_insert_last(arr, 20);
	sa_insert_last(arr, 30);
	sa_insert_at(arr, 1, 15); // Insert 15 at index 1

	// Display array
	printf("Array after insertions: ");
	sa_display(arr);

	// Modify value at index 2
	sa_modify_at(arr, 2, 25);
	printf("Array after setting index 2 to 25: ");
	sa_display(arr);

	// Remove value at index 1
	sa_remove_at(arr, 1);
	printf("Array after removing index 1: ");
	sa_display(arr);

	// Remove last value
	sa_remove_last(arr);
	printf("Array after removing last value: ");
	sa_display(arr);

	// Free resources
	sa_free(arr);
	return 0;
}