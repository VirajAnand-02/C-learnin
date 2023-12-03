#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int rightIndexFound = low-1;
    int current = low;

    for(current = low; current<=high; current++){
        if(arr[current] < pivot){
            rightIndexFound++;
            swap(&arr[current], &arr[rightIndexFound]);
        }
    }

    swap(&arr[high], &arr[rightIndexFound+1]);
    
    return rightIndexFound+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        // index pi is already sorted , sort next 
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int main(){
    int arr[] = {651,65,898,41,6454,516,6,6,65,1,8651,651,651,1,51,651,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, len-1);
    for(int i=0;i<len;i++){
        printf("%d, ", arr[i]);
    }
return 0;
}