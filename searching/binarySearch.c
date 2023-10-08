// Non duplicat Binary Search
#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr, int num, int F, int L){
    int ends[] = {F, L};
    int middle = (ends[0]+ends[1])/2;

    if(arr[middle] == num && ends[0] != ends[1]){
        printf("Found at index [%d]", middle);
    }
    else if(arr[middle] > num){
        // search left
        binarySearch(arr, num, F, middle);
    }
    else if(arr[middle] < num){
        // search right
        binarySearch(arr, num, middle, L);
    }
    else{
        printf("Not found");
    }
}
int main(){
    int arr[] = {1, 2, 3, 3, 5, 8, 9, 14, 16 , 78, 88 ,89 ,99 , 102, 150};
    int len = sizeof(arr)/sizeof(int);
    binarySearch(arr, 89, 0, len-1);// Conditions
return 0;
}