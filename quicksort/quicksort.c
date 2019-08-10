#include <string.h>
#include "quicksort.h"
#include "../comparators/comparators.h"

static void quicksort_rec_int(int *arr, int low, int high);
static void quicksort_rec_str(char** arr, int low, int high, int(*comp_func)(const char* a, const char* b));
static int partition_int(int *arr, int low, int high);
static int partition_str(char** arr, int low, int high, int(*comp_func)(const char* a, const char* b));
static void swap_int(int *x, int *y);
static void swap_str(char **x, char **y);

void quicksort_int(int* arr, int n){
    if(n <= 1){
        return;
    }
    if(arr == NULL){
        return;
    }
    quicksort_rec_int(arr, 0, n-1);
}

void quicksort_str(char** arr, int n, int(*comp_func)(const char* a, const char* b)){
    if(n <= 1){
        return;
    }
    if(arr == NULL){
        return;
    }
    quicksort_rec_str(arr, 0, n - 1, comp_func);
}

static void quicksort_rec_str(char** arr, int low, int high, int(*comp_func)(const char* a, const char* b)){
    int part;
    if(low < high){
        part = partition_str(arr, low, high, comp_func);

        quicksort_rec_str(arr, low, part - 1, comp_func);
        quicksort_rec_str(arr, part + 1, high, comp_func);
    }
}

static int partition_str(char** arr, int low, int high, int(*comp_func)(const char* a, const char* b)){
    // save the pivot value
    char pivot[1024];
    strncpy(pivot, arr[high], 1024);

    // Holds the variable of the parition between low and high values around the pivot
    int i = low - 1;
    int j;

    for(j = low; j <= high - 1; j++){
        if( (*comp_func)(arr[j], pivot) == 1){
            i++;
            swap_str(&arr[i], &arr[j]);
        }
    }
    swap_str(&arr[i+1], &arr[high]);
    return (i+1);
}

static void quicksort_rec_int(int *arr, int low, int high){
    int part;
    if(low < high){
        part = partition_int(arr, low, high);

        quicksort_rec_int(arr, low, part-1);
        quicksort_rec_int(arr, part + 1, high);
    }
}

static int partition_int(int *arr, int low, int high){
    //Save the pivot value
    int pivot = arr[high];

    //Holdes the variable of the partition between low and high values
    // around the pivot. (-1 subtracted to account for increment)
    int i = low - 1;
    int j;

    for(j = low; j <= high - 1; j++){
        if(arr[j] <= pivot){
            i++; // increase the low pivot
            swap_int(&arr[i], &arr[j]);
        }
    }
    // put the pivot in the proper place
    swap_int(&arr[i+1], &arr[high]);
    //return the pivot position
    return (i+1);
}

static void swap_int(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

static void swap_str(char **x, char **y){
    if(x == y){
        return;
    }
    char* temp = *x;
    *x = *y;
    *y = temp;
}