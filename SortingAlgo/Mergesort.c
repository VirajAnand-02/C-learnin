#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int const left, int const mid, int const right){
    int n1 = mid-left +1, n2 = right-mid;
    int leftArr[n1], rightArr[right-mid];
    int i = 0; // left arr pointer
    int j = 0; // right arr pointer
    int k = left; // main array pointer

    //copy data into sub array
    for(int i = 0; i < n1;i++) leftArr[i]  = arr[left+i];
    for(int i = 0; i < n2;i++) rightArr[i] = arr[i+mid+1];
    // actual sorted mearging
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // remaning left
    while (i<n1){
        arr[k] = leftArr[i];
        k++;
        i++;
    }
    // remaning right
    while (j<n2){
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int lower, int upper){
    if(lower<upper){
        int mid = lower + (upper-lower)/2;
        // sort right
        mergeSort(arr, lower, mid );
        // sort left
        mergeSort(arr, mid+1, upper);
        // merge
        merge(arr, lower, mid, upper);
    }    

}
int main(){
    int arr[] = {651,65,898,41,6454,516,6,6,65,1,8651,651,651,1,51,651,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, len-1);
    // printing array
    for(int i=0;i<len;i++){
        printf("%d, ", arr[i]);
    }
return 0;
}
