
#include <stdio.h>

void print_array(int *a, int size){
    printf("[");
    for(int i=0; i<size; i++){
        printf("%d", a[i]);
        if(i<size-1)
            printf(",");
    }
    printf("]");
}

extern inline void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int *arr, int size){
    int i,j;
    for(i=0; i< size; i++){
        for (j=0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

