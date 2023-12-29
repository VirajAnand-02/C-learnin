// Non duplicat Binary Search
#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr, int num, int F, int L){
    int mid = F + (L-F)/2;
    printf("mid : %d ", mid);
    printf("f : %d ", F);
    printf("l : %d ", L);
    printf("\n");
    if(F == L-1 ){
        printf("not found");
        return -1;
    }
    if(arr[mid] == num){
        printf("found at index {%d}", mid);
        return mid;
    }
    else if (num > arr[mid]){// search right
        binarySearch(arr, num, mid, L);
    }
    else if (num < arr[mid]){// search left
        binarySearch(arr, num, F, mid);
    }
}
int main(){
    int arr[] = {1, 2, 3, 3, 5, 8, 9, 14, 16 , 78, 88 ,89 ,99 , 102, 150};
    int len = sizeof(arr)/sizeof(int);
    binarySearch(arr, 16, 0, len-1);// Conditions
return 0;
}