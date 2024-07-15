#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("input number: ");
    scanf("%d", &num);
    num & 1 == 1 ? printf("Odd") : printf("Even");
return 0;
}
