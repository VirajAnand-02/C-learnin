#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    fgets(str, 1000, stdin);
    int n=strlen(str);
    str[n-1]='\0';
    printf("%s", str);
return 0;
}