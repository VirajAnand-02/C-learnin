#include<stdio.h>
int main(){// WAP that copies one string into another
    char a[10000]="asmhdbs akjd  asdkj asd\n", b[10000];
    int i=0;
    while(a[i] != '\0'){
        b[i]=a[i];
        i++;
    }
    printf("content of b : %s", b);
    i=0;
    // while (b[i]!='\0'){
    //     printf("%c", b[i]);
    //     i++;
    // }
return 0;
}