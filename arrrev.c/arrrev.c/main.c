//
//  main.c
//  arrrev.c
//
//  Created by Sarvagya Singh on 17/08/23.
//
#include <stdio.h>
 
// Function to swap two memory contents
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Function to reverse the array through pointers
void reverse(int array[], int array_size)
{
    // pointer1 pointing at the beginning of the array
    int *pointer1 = array,
 
        // pointer2 pointing at end of the array
        *pointer2 = array + array_size - 1;
    while (pointer1 < pointer2) {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--;
    }
}
 
// Function to print the array
void print(int* array, int array_size)
{
    // Length pointing at end of the array
    int *length = array + array_size,
 
        // Position pointing to the beginning of the array
        *position = array;
    printf("Array = ");
    for (position = array; position < length; position++)
        printf("%d ", *position);
}
 
// Driver function
int main()
{
    // Array to hold the values
    int array[] = { 2, 4, -6, 5, 8, -1 };
 
    printf("Original ");
    print(array, 6);
 
    printf("Reverse ");
    reverse(array, 6);
    print(array, 6);
    return 0;
}
