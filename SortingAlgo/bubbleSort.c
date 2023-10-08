#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble(int arr[], int len){
    for(int i = 0;i<len;i++){
        for (int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main(){
    int arr[] = {651,65,898,41,6454,516,6,6,65,1,8651,651,651,1,51,651,6};
    int len = sizeof(arr)/sizeof(int);
    bubble(arr, len);
    for(int i=0;i<len;i++){
        printf("%d, ", arr[i]);
    }
return 0;
}