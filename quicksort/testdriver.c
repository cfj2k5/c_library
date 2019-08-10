#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "../comparators/comparators.h"

int main(void){
    int arr[] = {3, 62, 32, 34, 1, 532, 8};
    int i;
    int n = 7;
    char** strArr;
    int nStr = 5;
    strArr = (char**)malloc(nStr * sizeof(char*));
    for(i = 0; i < nStr; i++){
        strArr[i] = malloc(512 * sizeof(char));
    }
    strncpy(strArr[0], "bbb", 512);
    strncpy(strArr[1], "a", 512);
    strncpy(strArr[2], "abc", 512);
    strncpy(strArr[3], "hello", 512);
    strncpy(strArr[4], "what", 512);

    char strTestA[] = "aabcc";
    char strTestB[] = "dcba";
    int cmpRes = -5;

    printf("Array before sorting...\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    quicksort_int(arr, n);
    printf("Array after sorting..\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



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

    /* Testing the sort functions */
    printf("**** String Sort Functions Tests *****\n");
    printf("Original string list...\n");
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }
    printf("Sorted list using ascending order (non-descending)\n");
    quicksort_str(strArr, nStr, cmp_func_lexographic_sort);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list using descending order (non-ascending)\n");
    quicksort_str(strArr, nStr, cmp_func_lexographic_sort_reverse);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list based on number of unique characters\n");
    quicksort_str(strArr, nStr, cmp_func_number_of_distinct_characters);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    printf("Sorted list based on number of characters\n");
    quicksort_str(strArr, nStr, cmp_func_length);
    for(i = 0; i < nStr; i++){
        printf("%s\n", strArr[i]);
    }

    return 0;
}