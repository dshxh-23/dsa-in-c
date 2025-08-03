
/*
    C Program: Comprehensive Guide to Pointers
    ------------------------------------------

    This program demonstrates fundamental and advanced pointer concepts in C. Each section is thoroughly commented with explanations, theory, and use-cases.
    
    Topics covered:
        1. Introduction to Pointers
        2. Basic Pointer Syntax
        3. Void Pointers
        4. Pointer Arithmetic
        5. Pointers as Function Arguments
        6. Pointers to Pointers
        7. Pointers and Arrays
        8. Arrays as Function Arguments
        9. Character Arrays and Pointers
        10. Pointers and 2D/Multi-dimensional Arrays
        11. Pointers and Dynamic Memory
        12. Dynamic Memory Allocation (malloc, calloc, realloc, free)
        13. Function Pointers
        14. Function Pointers and Callbacks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Introduction to Pointers
---------------------------

    A pointer is a variable that stores the memory address of another variable, rather than the value itself.
    Pointers are fundamental to C, enabling direct memory access, dynamic memory management, efficient array handling,
    function callbacks, and more. They are essential for building complex data structures and for writing efficient code.

    Types of Pointers:
        int*    - pointer to integer
        char*   - pointer to character
        float*  - pointer to float
        double* - pointer to double

    Why do pointers have types? Why not a single generic pointer type for all variables?
        The type of a pointer is crucial because pointers are not only used to store addresses, but also to dereference and manipulate the value at that address. When dereferencing, the compiler must know how many bytes to read or write, which is determined by the pointer's type. For example, an int pointer (int*) tells the compiler to treat the memory as an integer (typically 4 bytes), while a char pointer (char*) treats it as a single byte.

        If you store the address of an integer in a char pointer and dereference it, you will only access the first byte of the integer, potentially leading to incorrect results. Thus, pointer types ensure correct interpretation and manipulation of memory.
*/

void intro_to_pointers() {
    int x = 10;
    int* p = &x; // p stores the address of x
    printf("Introduction to Pointers\n");
    printf("  Value of x: %d\n", x);
    printf("  Address of x: %p\n", (void*)&x);
    printf("  Value of p (address of x): %p\n", (void*)p);
    printf("  Value pointed by p: %d\n", *p);
    printf("\n");
    /*
    EXAMPLE:
    Consider an integer variable at address 2020. An int pointer will correctly dereference all 4 bytes (2020-2023).
    If a char pointer is used, only the first byte (2020) is accessed, which may yield an incorrect value.
    This demonstrates why pointer types are necessary for correct memory access.
    */
    printf("  NOTE: Pointer types ensure correct interpretation of memory when dereferencing.\n\n");
}

/*
2. Basic Pointer Syntax
-----------------------
    Declaring, assigning, and dereferencing pointers are foundational skills in C.
    Declaration: int *ptr; assigns a pointer to int.
    Assignment: ptr = &a; stores the address of variable a in ptr.
    Dereferencing: *ptr accesses or modifies the value at the address stored in ptr.

    Use-case: Indirectly accessing or modifying variables, enabling functions to change values outside their scope.
*/
void basic_pointer_syntax() {
    int a = 5;
    int* ptr = &a;
    printf("Basic Pointer Syntax\n");
    printf("  a = %d, *ptr = %d\n", a, *ptr);
    *ptr = 20; // Modifies a via pointer
    printf("  After *ptr = 20, a = %d\n\n", a);

    /*
    NOTE:
        Dereferencing a pointer without initializing it (i.e., just after declaration) leads to undefined behavior.
        The pointer will contain a garbage address, and accessing it may crash the program or corrupt memory.
        So, always initialize pointers before dereferencing.
    */
}

/*
3. Void Pointers
----------------
    A void pointer (void *) is a special type of pointer that can hold the address of any data type. However, it cannot be dereferenced directly because its type is unknown to the compiler. To access the value, you must cast it to the appropriate type.

    Use-case: Generic functions such as memory allocation (malloc returns void*), or functions that operate on data of unknown type.

    EXAMPLE: void *vp; int i = 10; vp = &i; // To access i: *(int*)vp
*/
void void_pointers() {
    int i = 42;
    double d = 3.14;
    void* vp;
    vp = &i;
    printf("Void Pointers\n");
    printf("  vp points to int: %d\n", *(int*)vp);
    vp = &d;
    printf("  vp points to double: %.2f\n\n", *(double*)vp);
}

/*
4. Pointer Arithmetic
---------------------
    Pointer arithmetic allows you to move pointers forward or backward in memory. When you increment a pointer, it advances by the size of its type (e.g., int* moves by 4 bytes). This is especially useful for iterating through arrays, as array elements are stored contiguously in memory.

    Valid operations: increment (++), decrement (--), addition (+), subtraction (-), difference between two pointers.

    Use-case: Efficiently traversing arrays and data structures.
*/
void pointer_arithmetic() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;
    printf("Pointer Arithmetic\n");
    for(int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d, *(p+%d) = %d\n", i, arr[i], i, *(p+i));
    }
    printf("\n");
}

/*
5. Pointers as Function Arguments
---------------------------------
    Passing pointers to functions allows those functions to modify the original variables in the caller's scope. This is because the function receives the address of the variable, not a copy of its value.

    Use-case: Swapping values, returning multiple results, modifying arrays or structures in-place.

    EXAMPLE: void swap(int *a, int *b) { ... } // Swaps values at the given addresses.
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void pointers_as_function_args() {
    int x = 1, y = 2;
    printf("Pointers as Function Arguments\n");
    printf("  Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("  After swap: x = %d, y = %d\n\n", x, y);
}

/*
6. Pointers to Pointers
-----------------------
    A pointer to a pointer (e.g., int **pp) stores the address of another pointer. This enables the creation of multi-level indirection, which is useful for dynamic multi-dimensional arrays, and for functions that need to modify the value of a pointer argument (e.g., to allocate memory and update the caller's pointer).

    Use-case: Dynamic 2D arrays, linked data structures, modifying pointer arguments in functions.
*/
void pointers_to_pointers() {
    int val = 100;
    int* p = &val;
    int** pp = &p;
    printf("Pointers to Pointers\n");
    printf("  val = %d, *p = %d, **pp = %d\n\n", val, *p, **pp);
}

/*
7. Pointers and Arrays
----------------------
    In C, the name of an array is a constant pointer to its first element. This allows you to use pointers to traverse arrays efficiently using pointer arithmetic.

    EXAMPLE: int arr[3]; int *p = arr; // p points to arr[0]

    NOTE: arr[4] and *(arr+4) MEAN THE SAME THING.

    Use-case: Efficient array traversal, passing arrays to functions, manipulating data in-place.
*/
void pointers_and_arrays() {
    int arr[3] = {7, 8, 9};
    int* p = arr;               // Alternatively, you can just use the arr pointer only..
    printf("Pointers and Arrays\n");
    for (int i = 0; i < 3; i++) {
        printf("  arr[%d] = %d, *(p+%d) = %d\n", i, arr[i], i, *(p+i));
    }
    printf("\n");
}

/*
8. Arrays as Function Arguments
------------------------------
    When you pass an array to a function, what is actually passed is a pointer to its first element. Note that the size of the array is not automatically known to the function, so it must be passed as a separate argument. This allows functions to process arrays of any size, but also means you must be careful to avoid out-of-bounds access.

    Use-case: Processing arrays, implementing generic functions for different array sizes.
*/
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
}
void arrays_as_function_args() {
    int arr[4] = {1, 2, 3, 4};
    printf("Arrays as Function Arguments\n");
    print_array(arr, 4);
    printf("\n");
}

/*
9. Character Arrays and Pointers
--------------------------------
    In C, strings are represented as arrays of characters terminated by a null character ('\0').
    Pointers are commonly used to manipulate and traverse strings efficiently.

    EXAMPLE: char str[] = "Hello"; char *p = str;

    NOTE:
        A character pointer does not inherently know the length of a string. Instead, it relies on the null terminator ('\0') to determine where the string ends. Functions and loops that process strings keep reading characters until they encounter this special character. Forgetting the null terminator can lead to undefined behavior or reading garbage data.

        This null terminator '\0' is automatically added when you declare and initialize a charater array using a string literal, as seen here: char str[] = "Hello!";
        However, if you're initializing a charater array manually, you must add the null terminator yourself, otherwise it won't be a proper string:-
            char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Correct
            char str[5] = {'H', 'e', 'l', 'l', 'o'};       // No null terminator! Not a proper string

    Use-case: String manipulation, passing strings to functions, efficient text processing.
*/
void char_arrays_and_pointers() {
    char str[] = "Hello, pointers!";
    char* p = str;
    printf("Character Arrays and Pointers\n");
    printf("  String: %s\n", str);
    printf("  First char via pointer: %c\n", *p);
    printf("  All chars: ");
    while (*p) {
        printf("%c ", *p);
        p++;
    }
    printf("\n\n");
}


/*
10. Pointers and 2D/Multi-dimensional Arrays
--------------------------------------------
    In C, a 2D array is essentially an array of arrays, stored in contiguous memory in row-major order.
    For example, int mat[2][3] creates a matrix with 2 rows and 3 columns, laid out in memory as:
        mat[0][0], mat[0][1], mat[0][2], mat[1][0], mat[1][1], mat[1][2]

    Pointer relationships:
        - mat is a pointer to the first row (mat[0]), and mat[0] is a pointer to the first element of that row.
        - Accessing elements: mat[i][j] is equivalent to *(*(mat + i) + j)

    Traversing a 2D array with pointers:
        - Nested traversal: Use two loops, incrementing row and column indices, and access elements via pointer arithmetic.
        - Linear traversal: Treat the 2D array as a contiguous block and use a single pointer to iterate through all elements in row-major order.
            int* p = &mat[0][0];
            for (int k = 0; k < rows * cols; k++) {
                // *(p + k) accesses each element sequentially
            }

    NOTE:
        - Pointer arithmetic works because the memory for mat is contiguous.
        - This technique is useful for passing 2D arrays to functions or performing operations on all elements efficiently.

    Use-case: Matrix operations, image processing, dynamic multi-dimensional arrays.
*/
void pointers_and_2d_arrays() {
    int mat[2][3] = {{1,2,3}, {4,5,6}};
    printf("Pointers and 2D Arrays\n");

    // Accessing elements using both array and pointer notation
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  mat[%d][%d] = %d, *(*(mat+%d)+%d) = %d\n", i, j, mat[i][j], i, j, *(*(mat+i)+j));
        }
    }

    // Linear traversal using a pointer to the first element
    printf("  Linear traversal using pointer: ");
    int* p = &mat[0][0];
    for (int k = 0; k < 2 * 3; k++) {
        printf("%d ", *(p + k));
    }
    printf("\n\n");
}

/*
11. Pointers and Dynamic Memory
------------------------------
    In C, you can allocate memory dynamically (at runtime) using pointers. This means you can create arrays or data structures whose size is not known until the program is running.

    Why use dynamic memory?
        - Static arrays (e.g., int arr[10]) have fixed size, set at compile time.
        - Dynamic memory lets you create flexible, variable-sized structures (e.g., int* arr = malloc(n * sizeof(int));).

    How does it work?
        - Functions like malloc, calloc, and realloc return a pointer to a block of memory in the heap.
        - You use this pointer to access and manipulate the memory.
        - When done, you must free the memory using free() to avoid memory leaks.

    EXAMPLE:
        int* arr = malloc(n * sizeof(int)); // Allocates space for n integers
        // Use arr as a normal array: arr[0], arr[1], ...
        free(arr); // Release the memory

    NOTE:
        - malloc(), calloc() and realloc() always return a void pointer. ALWAYS type-cast the void pointer to the required type.
        - Always check if malloc/calloc/realloc returns NULL (allocation failure).
        - Forgetting to free memory leads to memory leaks (unused memory that can't be reclaimed).

    Use-case: Creating dynamic arrays, linked lists, trees, and other data structures that grow or shrink during program execution.
*/
void pointers_and_dynamic_memory() {
    int n = 5;
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Pointers and Dynamic Memory\n");
    for (int i = 0; i < n; i++) arr[i] = i * i;
    for (int i = 0; i < n; i++) printf("  arr[%d] = %d\n", i, arr[i]);
    free(arr);
    printf("\n");
}

/*
12. Dynamic Memory Allocation: malloc, calloc, realloc, free
-----------------------------------------------------------
    C provides four main functions for managing dynamic memory:

    1. malloc(size): Allocates a block of memory of given size (in bytes). Contents are uninitialized (may contain garbage values).
        EXAMPLE: int* a = malloc(3 * sizeof(int));

    2. calloc(num, size): Allocates memory for an array of num elements, each of given size, and initializes all bytes to zero.
        EXAMPLE: int* b = calloc(3, sizeof(int));

    3. realloc(ptr, new_size): Changes the size of a previously allocated memory block. May move the block to a new location.
        EXAMPLE: a = realloc(a, 5 * sizeof(int));

    4. free(ptr): Releases previously allocated memory so it can be reused by the system.

    Why use these?
        - malloc/calloc let you create arrays or structures whose size is determined at runtime.
        - realloc lets you resize arrays as needed (e.g., growing a dynamic array).
        - free prevents memory leaks by releasing memory you no longer need.

    How is memory freed using free(ptr)?
        The memory allocator (used by malloc) keeps track of size of each allocated block internally. When we call free(ptr), we pass the address that was returned by malloc. The allocator looks up it;s internal records and frees the entire block that starts at that address.

    NOTE:
        - Always check if malloc/calloc/realloc returns NULL (allocation failure).
        - Never use memory after it has been freed (dangling pointer).
        - Always free every block you allocate.

    Use-case: Building flexible data structures, managing large datasets, implementing custom memory management.
*/
void dynamic_memory_allocation() {
    int* a = (int*)malloc(3 * sizeof(int)); // malloc
    int* b = (int*)calloc(3, sizeof(int)); // calloc
    printf("Dynamic Memory Allocation\n");
    for (int i = 0; i < 3; i++) a[i] = i+1;
    printf("  malloc: ");
    for (int i = 0; i < 3; i++) printf("%d ", a[i]);
    printf("\n  calloc: ");
    for (int i = 0; i < 3; i++) printf("%d ", b[i]);
    printf("\n");
    // realloc
    a = (int*)realloc(a, 5 * sizeof(int));
    a[3] = 4; a[4] = 5;
    printf("  realloc: ");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    free(a); free(b);
    printf("  Memory freed.\n\n");
}

/*
13. Function Pointers
---------------------
    In C, you can create pointers that point to functions, just like you can have pointers to variables.

    What exactly are function pointers?
        The code written in high level language is converted into machine understandable code using a compiler. Our code is basically converted into a set of instructions, which live in the stack section of the main memory (RAM) of the system.
        
        The instruction at the lowest memory is executed first in the increasing order of the address of the memory, until and unless the instruction itself is to jump to another instruction at a specific memory. This is exactly what happens during function calls.

        So, a pointer which points to a function is actually the address of the 1st instruction of that function block. The last instruction of the function block is to jump back to the instruction that initially called the function. This is how the control is returned back to the function.
        
    Why use function pointers?
        - They allow you to call functions indirectly (useful for callbacks and event handling).
        - You can pass functions as arguments to other functions, enabling flexible and customizable behavior.
        - You can create tables of functions (e.g., for menu systems or plugin architectures).

    SYNTAX:
        return_type (*pointer_name)(parameter_types) = function_name;
        EXAMPLE: int (*func_ptr)(int, int) = add;

    CONCEPT: Function decay
        Here, we didn't add an & to the function name. This is bcuz of a concept called function decay, where a function name without parenthesis automatically breaks down into the function address.

    HOW TO USE:
        - Assign a function to a pointer: fp = add;
        - Call the function via the pointer: fp(2, 3);

    NOTE:
        - The function pointer's type must match the function's signature.
        - Always write the name of funcPtr, preceeded with an *, in parenthesis. This is due to the following reason:
            int (*func_ptr)(int, int) = add;    =>  pointer to a function
            int *func_ptr(int, int) = add;      === int* func_ptr(int, int) = add;  =>  We're declaring a function with the return type as a pointer to an int.

    Use-case: Callbacks, event handling, flexible APIs, plugin systems, custom behavior selection.
*/
int add(int a, int b) {return a+b;}
int multiply(int a, int b) {return a*b;}
void function_pointers() {
    int (*fp)(int, int);
    printf("Function Pointers\n");
    fp = add;
    printf("  add(2,3) via fp: %d\n", fp(2,3));
    fp = multiply;
    printf("  multiply(2,3) via fp: %d\n\n", fp(2,3));
}

/*
14. Function Pointers and Callbacks
-----------------------------------
    A callback is a function that is passed as an argument to another function, allowing the called function to invoke it at the appropriate time.

    How does this work in C?
        - You define a function pointer as a parameter in your function.
        - The caller passes the address of a function to be called back.
        - The called function uses the pointer to invoke the callback.

    EXAMPLE:
        void operate(int x, int y, int (*func)(int, int));
        // operate can use func to perform different operations (add, multiply, etc.)

    Why use callbacks?
        - They allow you to customize behavior (e.g., sorting with different comparison functions).
        - Useful in event-driven programming, libraries, and APIs where the user provides custom logic.

    NOTE:
        - The callback function must match the expected signature.
        - This technique is foundational for flexible and reusable code in C.

    Use-case: Custom sorting, event-driven programming, flexible APIs, strategy patterns, plugin architectures.
*/
void operate(int x, int y, int (*func)(int, int)) {
    printf("  Result: %d\n", func(x, y));
}
void function_pointers_and_callbacks() {
    printf("Function Pointers and Callbacks\n");
    printf("  Using add: ");
    operate(5, 7, add);
    printf("  Using multiply: ");
    operate(5, 7, multiply);
    printf("\n");
}

int main() {
    printf("\n\n==== Comprehensive Pointer Concepts in C ====\n\n");

    // intro_to_pointers();
    // basic_pointer_syntax();
    // void_pointers();
    // pointer_arithmetic();
    // pointers_as_function_args();
    // pointers_to_pointers();
    // pointers_and_arrays();
    // arrays_as_function_args();
    // char_arrays_and_pointers();
    // pointers_and_2d_arrays();
    // pointers_and_dynamic_memory();
    // dynamic_memory_allocation();
    // function_pointers();
    // function_pointers_and_callbacks();
    
    printf("==== End of Program ====\n\n");
    return 0;
}
