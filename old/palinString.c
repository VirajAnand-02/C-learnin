#include<stdio.h>
#include<string.h>
int main(){
    char str[10000];
    printf("Input string : ");
    scanf("%s", &str);
    int n = strlen(str), val=1;
    for(int i=0; i<n/2; i++){
        if(str[i]!=str[n-1-i]){
            val = 0;
            break;
        }
    }
    val?printf("Palindrome\n"):printf("Not a Palindrome\n");
return 0;
}