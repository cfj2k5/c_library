#ifndef __SELECTIONSORT__
#define __SELECTIONSORT__ 

void selectionSort_int(int arr[], int n);
void selectionSort_string(char** arr, const int n, int(*str_cmp_func)(const char* a, const char* b));


#endif