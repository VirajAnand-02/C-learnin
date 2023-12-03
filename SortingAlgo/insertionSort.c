#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for( i =1; i<n;i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){ // shift pos to make space for "key"
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
        
}

int main(){
    int arr[] = {651,65,898,41,6454,516,6,6,65,1,8651,651,651,1,51,651,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, len);
    for(int i=0;i<len;i++){
        printf("%d, ", arr[i]);
    }
return 0;
}