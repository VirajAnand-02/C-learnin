#include<stdio.h>
#include<stdlib.h>

int multBitwise(int num){
    int ans = -(num << 2);
    return ans;
}

int main(){
    int num;
    printf("enter a number: ");
    scanf("%d", &num);
    printf("%d", multBitwise(num));
return 0;
}