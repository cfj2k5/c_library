#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectionSort.h"

static void swap_int(int *x, int *y);
static void swap_str(char** x, char** y);

/*
    Selection sort for an integer array. O(n^2) time.
 */
void selectionSort_int(int arr[], int n){
    if(n <= 1){
        return;
    }
    if(arr == NULL){
        return;
    }
    int min_idx;
    int i,j;
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap_int(&arr[i], &arr[min_idx]);
    }
}

/*
    Selection sort for an array of strings. O(n^2) time.
 */
void selectionSort_string(char** arr, const int n, int(*str_cmp_func)(const char* a, const char* b)){
    if(n <= 1){
        return;
    }
    if(arr == NULL){
        return;
    }
    int min_idx;
    int i,j;
    for(int i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++){
            if( (*str_cmp_func)(arr[j], arr[min_idx]) == 1){
                min_idx = j;
            }
        }
        swap_str(&arr[i], &arr[min_idx]);
    }
}

/*
    Simple int swap.
 */
static void swap_int(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
    Simple string swap
 */
static void swap_str(char **x, char **y){
    /* Avoid copying a string on to itself */
    if(x == y){
        return;
    }
    char* temp = *x;
    *x = *y;
    *y = temp;

}
