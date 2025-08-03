#include <stdio.h>

/*
Bubble Sort Algorithm:
--------------------------------------------
Bubble sort is a simple comparison-based sorting algorithm. It works by repeatedly stepping through the list, comparing adjacent elements and swapping them if they are in the wrong order. This process is repeated until the list is sorted.

STEPS:
    1.  Start from the beginning of the array.
    2.  Compare each pair of adjacent elements.
    3.  If the pair is out of order (based on the comparison function), swap them.
    4.  After each pass, the largest (or smallest, depending on order) element "bubbles up" to its correct position at the end of the array.
    5.  Repeat the process for the remaining unsorted part of the array.
    6.  Continue until no swaps are needed, or until all passes are complete.

COMPLEXITY:
    Time Complexity: O(n^2) in the worst and average case.
    Space Complexity: O(1) (in-place sorting).

NOTE:
    This implementation uses a callback function to allow sorting in ascending or descending order.
*/



// ------------------------------------


/*
 * Prints the elements of an integer array.
 * @param arr: Pointer to the array to print
 * @param size: Number of elements in the array
 */
void print_sorted_arr(int* arr, int size) {
    for(int i=0; i<size; i++) {printf("%d ", arr[i]);}
    printf("\n");
}



/*
 * Comparison function for ascending order.
 * Returns 1 if a < b, else 0.
 * Used as a callback for sorting.
 */
int ascending(int a, int b) {return a < b;}
/*
 * Comparison function for descending order.
 * Returns 1 if a > b, else 0.
 * Used as a callback for sorting.
 */
int descending(int a, int b) {return a > b;}



/*
 * Swaps the values of two integer variables.
 * @param a: Pointer to the first integer
 * @param b: Pointer to the second integer
 */
void swap_values(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



/*
 * Sorts an integer array using the bubble sort algorithm.
 * Uses a callback comparison function to determine order.
 * @param arr: Pointer to the array to sort
 * @param size: Number of elements in the array
 * @param cmp: Pointer to comparison function (returns 1 if in order, 0 if not)
 */
void bubble_sort_array(int* arr, int size, int (*cmp)(int, int)) {
    // Outer loop: controls the number of passes (size-1 passes needed)
    for(int i=0; i<size-1; i++) {
        // Inner loop: compares adjacent elements in the unsorted part
        for(int j=0; j<(size-1)-i; j++) {
            // If the current pair is NOT in the correct order, swap them
            // cmp(arr[j], arr[j+1]) returns 1 if in order, 0 if not
            if(!(cmp(arr[j], arr[j+1]))) {
                swap_values(arr+j, arr+(j+1)); // Swap the elements
            }
        }
        // After each pass, the largest/smallest element is at the end
    }
    // Array is sorted after all passes
}


/*
 * Main function
 */
int main() {
    int arr[5] = {4,2,7,1,6};
    int size = sizeof(arr)/4;
    sort_array(arr, 5, ascending);
    for(int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
}