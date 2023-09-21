#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=0;
    printf("Enter a number : ");
    scanf("%d", &n);
    if(n > 7)
        printf("Number %d is hot !!!", n);
    else
        printf("%d is not hot :(", n);
return 0;
}