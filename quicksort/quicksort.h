#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

void quicksort_int(int* arr, int n);
void quicksort_str(char** arr, int n, int(*comp_func)(const char* a, const char*b));
#endif