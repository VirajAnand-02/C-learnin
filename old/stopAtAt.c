#include<stdio.h>
#include<conio.h>
int main(){
    int i=0;
    char str[10000], a;
    printf("Start : ");
    while(a != '&'){
        if(a = getch()){
            str[i] = a;
            i++;
            printf("%c",a);
        }
    }
    printf("\n%s\n", str);
return 0;
} 