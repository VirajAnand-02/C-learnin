#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for( i =1; i<n;i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){