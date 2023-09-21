#include<stdio.h>
int chkPrime(int n){
    if(n <= 1)
        return 0;
    for(int i=2;i<n/2+1;i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}
int main(){
    int prime[10];
    int *arr=prime;
    for(int i=0,n=1;i<10;n++){
        if(chkPrime(n)){
            // printf("%d \n",n);
            *arr = n;
            arr++;
            i++;
        }
    }
    for(int i =0;i<10; i++){
        printf("%d \n", prime[i]);
    }
return 0;
}