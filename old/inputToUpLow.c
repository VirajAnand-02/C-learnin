#include<stdio.h>
#include<string.h>
int main(){
    char text[100000];
    printf("Enter text : ");
    scanf("%s", &text);
    printf("%d", strlen(text));
    for(int i=0, n=strlen(text); i<n; i++){
        if(text[i]<=122 && text[i]>=97){
           text[i] -= 32;
        }
    }
    printf("Upper case : %s\n", text);
    for(int i=0; i<strlen(text); i++){
        text[i] += 32;
    }
    printf("Lower case : %s\n", text);
return 0;
}