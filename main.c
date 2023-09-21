#include<stdio.h>
int mod(int n){
    if(n>0){
        return n;
    }
    else if(n<0){
        return -n;
    }
    return 0;
}
int main(){
    int n, leastPos = 0, least;
    scanf("%d", &n);
    int a[n];
    char c[101];
    // for(int i = 0;i<n; i++){
    //     scanf("%d", &a[i]);
    // }
    scanf("%s", c);
    int k=0, l=0;
    while(k<n){
        if()

    }
    least = a[0];
    for(int i=0;i<n;i++){
        if(mod(a[i]) < least){
            leastPos = i;
        }
    }
    printf("%d", mod(a[leastPos]));
return 0;
}