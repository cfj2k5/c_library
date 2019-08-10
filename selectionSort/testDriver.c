#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectionSort.h"
#include "../comparators/comparators.h"

void printArray(int arr[], int size);

// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 9, 4, 0, 0, 25, 12, 22, 11};
    char** strArr;
    int nStr = 5;
    int i;
    strArr = (char**)malloc(nStr * sizeof(char*));
    for(i = 0; i < nStr; i++){
        strArr[i] = malloc(512 * sizeof(char));
    }
    strncpy(strArr[0], "bbb", 512);
    strncpy(strArr[1], "a", 512);
    strncpy(strArr[2], "abc", 512);
    strncpy(strArr[3], "hello", 512);
    strncpy(strArr[4], "what", 512);

    int n = sizeof(arr)/sizeof(arr[0]);

    char strTestA[] = "aabcc";
    char strTestB[] = "dcba";
    int cmpRes = -5;

    printf("Unsorted array:\n");
    printArray(arr, n);
    selectionSort_int(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n);

    printf("**** Compare Functions Tests *****\n");
    /* cmp_func_lexographic_sort */
    cmpRes = cmp_func_lexographic_sort(strTestA, strTestB);
    if(cmpRes == 1){
        printf("Value: %d. %s is before %s\n", cmpRes, strTestA, strTestB);
    }else if(cmpRes == -1){
        printf("Value: %d, %s is before %s\n", cmpRes, strTestB, strTestA);
    }else{
        printf("Value: %d, %s is equal to %s\n", cmpRes, strTestB, strTestA);
    }

    /* cmp_func_lexographic_sort_reverse */
    cmpRes = cmp_func_lexographic_sort_reverse(strTestA, strTestB);
    if(cmpRes == 1){
        printf("Value: %d. %s is before %s\n", cmpRes, strTestA, strTestB);
    }else if(cmpRes == -1){
        printf("Value: %d, %s is before %s\n", cmpRes, strTestB, strTestA);
    }else{
        printf("Value: %d, %s is equal to %s\n", cmpRes, strTestB, strTestA);
    }

    /* cmp_func_number_of_distinct_characters */
    cmpRes = cmp_func_number_of_distinct_characters(strTestA, strTestB);
    if(cmpRes == 1){
        printf("Value: %d. %s has less distinct characters than %s\n", cmpRes, strTestA, strTestB);
    }else if(cmpRes == -1){
        printf("Value: %d, %s has less distinct characters than %s\n", cmpRes, strTestB, strTestA);
    }else{
        printf("Value: %d, %s has the same distinct characters as %s\n", cmpRes, strTestB, strTestA);
    }

    /* cmp_func_length */
    cmpRes = cmp_func_length(strTestA, strTestB);
    if(cmpRes == 1){
        printf("Value: %d. %s has less characters than %s\n", cmpRes, strTestA, strTestB);
    }else if(cmpRes == -1){
        printf("Value: %d, %s has less characters than %s\n", cmpRes, strTestB, strTestA);
    }else{
        printf("Value: %d, %s has the same characters as %s\n", cmpRes, strTestB, strTestA);
    }

    /* Testing the soft functions */
    printf("**** String Sort Functions Tests *****\n");
    printf("Original string list...\n");
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }
    printf("Sorted list using ascending order (non-descending)\n");
    selectionSort_string(strArr, nStr, cmp_func_lexographic_sort);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list using descending order (non-ascending)\n");
    selectionSort_string(strArr, nStr, cmp_func_lexographic_sort_reverse);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list based on number of unique characters\n");
    selectionSort_string(strArr, nStr, cmp_func_number_of_distinct_characters);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list based on number of characters\n");
    selectionSort_string(strArr, nStr, cmp_func_length);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }
    return 0; 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 