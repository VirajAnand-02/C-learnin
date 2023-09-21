#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[] = {1, 2};
    int toSearch, resultIndex = -1;
    printf("Element to search : ");
    scanf("%d", &toSearch);
    for(int i=0; i< sizeof(arr)/sizeof(int); i++){
        if(arr[i] == toSearch){
            resultIndex = i;
            break;
        }
    }
    if(resultIndex != -1){
        printf("Found Element %d at Index [%d]", toSearch, resultIndex);
    }
    else{
        printf("Element %d not found", toSearch);
    }

return 0;
}